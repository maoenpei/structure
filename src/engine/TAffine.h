#ifndef __BASE_AFFINE_H__
#define __BASE_AFFINE_H__

namespace engine{

	template<typename T>
	struct TAffine
	{
		T a, b, c, d, x, y;
		inline TAffine() : a(1), b(0), c(0), d(1), x(0), y(0){}
		inline TAffine(T _a, T _b, T _c, T _d, T _x, T _y) : a(_a), b(_b), c(_c), d(_d), x(_x), y(_y){}
		inline void contact(TAffine &aff, const TAffine &other){
			aff.a = a*other.a+c*other.b;
			aff.b = b*other.a+d*other.b;
			aff.c = a*other.c+c*other.d;
			aff.d = b*other.c+d*other.d;
			aff.x = a*other.x+c*other.y+x;
			aff.y = b*other.x+d*other.y+y;
		}
	};

	typedef TAffine<float> TAffinef;
	typedef TAffine<double> TAffined;
	
};

#endif

