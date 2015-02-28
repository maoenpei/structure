

#include "CNodeCamera3d.h"
#include <assert.h>
#include <math.h>

namespace engine{

void CNodeCamera3d::dispose(graphics::ITransformer * trans)
{
	trans->contact(Matrix);
}

void CNodeCamera3d::identity()
{
	Matrix.identity();
}

void CNodeCamera3d::move(float mx,float my)
{
	Matrix.v[12] += mx;
	Matrix.v[13] += my;
}

void CNodeCamera3d::scale(float sx,float sy)
{
	Matrix.v[0] *= sx;
	Matrix.v[1] *= sy;
	Matrix.v[4] *= sx;
	Matrix.v[5] *= sy;
	Matrix.v[8] *= sx;
	Matrix.v[9] *= sy;
	Matrix.v[12] *= sx;
	Matrix.v[13] *= sy;
}

void CNodeCamera3d::rotate(float sita)
{
	graphics::TMatrixf matrix(Matrix);
	float sn = sin(sita);
	float cs = cos(sita);

	Matrix.v[0] = cs * matrix.v[0] - sn * matrix.v[1];
	Matrix.v[1] = sn * matrix.v[0] + cs * matrix.v[1];
	Matrix.v[4] = cs * matrix.v[4] - sn * matrix.v[5];
	Matrix.v[5] = sn * matrix.v[4] + cs * matrix.v[5];
	Matrix.v[8] = cs * matrix.v[8] - sn * matrix.v[9];
	Matrix.v[9] = sn * matrix.v[8] + cs * matrix.v[9];
	Matrix.v[12] = cs * matrix.v[12] - sn * matrix.v[13];
	Matrix.v[13] = sn * matrix.v[12] + cs * matrix.v[13];
	
}

void CNodeCamera3d::move(const model::Vectorf &dist)
{
	Matrix.v[12] += dist.x;
	Matrix.v[13] += dist.y;
	Matrix.v[14] += dist.z;
}

void CNodeCamera3d::scale(float sx,float sy,float sz)
{
	Matrix.v[0] *= sx;
	Matrix.v[1] *= sy;
	Matrix.v[2] *= sz;
	Matrix.v[4] *= sx;
	Matrix.v[5] *= sy;
	Matrix.v[6] *= sz;
	Matrix.v[8] *= sx;
	Matrix.v[9] *= sy;
	Matrix.v[10] *= sz;
	Matrix.v[12] *= sx;
	Matrix.v[13] *= sy;
	Matrix.v[14] *= sz;
}

// make axis->T, sita->R
// G' = T-1 * R * T * G
void CNodeCamera3d::rotate(const model::Vectorf &axis, float sita)
{
	assert(false);
}

};


