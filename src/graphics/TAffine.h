#ifndef __BASE_AFFINE_H__
#define __BASE_AFFINE_H__

#include <string>

namespace graphics{

	template<typename T>
	struct TAffine
	{
		T v[6];
		inline TAffine(){
			memset(v, 0, sizeof(v));
			v[0] = 1;
			v[3] = 1;
		}
		inline TAffine(T _a, T _b, T _c, T _d, T _x, T _y){
			v[0] = _a;
			v[1] = _b;
			v[2] = _c;
			v[3] = _d;
			v[4] = _x;
			v[5] = _y;
		}
		inline TAffine(const TAffine &copy){
			memcpy(v, copy.v, sizeof(v));
		}
		inline void operator =(const TAffine &copy){
			memcpy(v, copy.v, sizeof(v));
		}
		inline void contact(TAffine &aff, const TAffine &other) const{
			aff.v[0] = v[0]*other.v[0]+v[2]*other.v[1];
			aff.v[1] = v[1]*other.v[0]+v[3]*other.v[1];
			aff.v[2] = v[0]*other.v[2]+v[2]*other.v[3];
			aff.v[3] = v[1]*other.v[2]+v[3]*other.v[3];
			aff.v[4] = v[0]*other.v[4]+v[2]*other.v[5]+v[4];
			aff.v[5] = v[1]*other.v[4]+v[3]*other.v[5]+v[5];
		}
	};

	typedef TAffine<float> TAffinef;
	typedef TAffine<double> TAffined;
	
};

#endif

