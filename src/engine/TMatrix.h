#ifndef __BASE_MATRIX_H__
#define __BASE_MATRIX_H__

#include <string>

namespace engine{

	template<typename T>
	struct TMatrix
	{
		T v[16];
		inline TMatrix(){
			memset(v, 0, sizeof(v));
			v[0] = v[5] = v[10] = v[15] = 1;
		}
		inline TMatrix(const TMatrix &copy){
			memcpy(v, copy.v, sizeof(v));
		}
		inline void operator =(const TMatrix &copy){
			memcpy(v, copy.v, sizeof(v));
		}
		inline void contact(TMatrix &mat, const TMatrix &other) const{
			mat.v[0] = v[0]*other.v[0] + v[4]*other.v[1] + v[8]*other.v[2] + v[12]*other.v[3];
			mat.v[1] = v[1]*other.v[0] + v[5]*other.v[1] + v[9]*other.v[2] + v[13]*other.v[3];
			mat.v[2] = v[2]*other.v[0] + v[6]*other.v[1] + v[10]*other.v[2] + v[14]*other.v[3];
			mat.v[3] = v[3]*other.v[0] + v[7]*other.v[1] + v[11]*other.v[2] + v[15]*other.v[3];
			
			mat.v[4] = v[0]*other.v[4] + v[4]*other.v[5] + v[8]*other.v[6] + v[12]*other.v[7];
			mat.v[5] = v[1]*other.v[4] + v[5]*other.v[5] + v[9]*other.v[6] + v[13]*other.v[7];
			mat.v[6] = v[2]*other.v[4] + v[6]*other.v[5] + v[10]*other.v[6] + v[14]*other.v[7];
			mat.v[7] = v[3]*other.v[4] + v[7]*other.v[5] + v[11]*other.v[6] + v[15]*other.v[7];
			
			mat.v[8] = v[0]*other.v[8] + v[4]*other.v[9] + v[8]*other.v[10] + v[12]*other.v[11];
			mat.v[9] = v[1]*other.v[8] + v[5]*other.v[9] + v[9]*other.v[10] + v[13]*other.v[11];
			mat.v[10] = v[2]*other.v[8] + v[6]*other.v[9] + v[10]*other.v[10] + v[14]*other.v[11];
			mat.v[11] = v[3]*other.v[8] + v[7]*other.v[9] + v[11]*other.v[10] + v[15]*other.v[11];
			
			mat.v[12] = v[0]*other.v[12] + v[4]*other.v[13] + v[8]*other.v[14] + v[12]*other.v[15];
			mat.v[13] = v[1]*other.v[12] + v[5]*other.v[13] + v[9]*other.v[14] + v[13]*other.v[15];
			mat.v[14] = v[2]*other.v[12] + v[6]*other.v[13] + v[10]*other.v[14] + v[14]*other.v[15];
			mat.v[15] = v[3]*other.v[12] + v[7]*other.v[13] + v[11]*other.v[14] + v[15]*other.v[15];
		}
	};

	typedef TMatrix<float> TMatrixf;
	typedef TMatrix<double> TMatrixd;
	
};

#endif


