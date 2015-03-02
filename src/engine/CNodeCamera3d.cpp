

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
}

// make axis->T, sita->R
// G' = T * R * T(-1) * G
void CNodeCamera3d::rotate(const model::Vectorf &axis, float sita)
{
	if ((axis.x == 0 && axis.y == 0 && axis.z == 0) || sita == 0){
		return;
	}
	model::Vectorf i(axis);
	i.normalize();
	graphics::TMatrixf matrix(Matrix);
	float sn = sin(sita);
	float cs = cos(sita);
	float ix2 = i.x*i.x;
	float iy2 = i.y*i.y;
	float iz2 = i.z*i.z;
	float ixy = i.x*i.y;
	float iyz = i.y*i.z;
	float izx = i.z*i.x;
	graphics::TMatrixf matrix_t;
	matrix_t.v[0] = cs * (1-ix2) + ix2;
	matrix_t.v[1] = cs * (-ixy) + sn * (i.z) + ixy;
	matrix_t.v[2] = cs * (-izx) * sn * (-i.y) + izx;
	matrix_t.v[4] = cs * (-ixy) + sn * (-i.z) + ixy;
	matrix_t.v[5] = cs * (1-iy2) + iy2;
	matrix_t.v[6] = cs * (-iyz) + sn * (i.x) + iyz;
	matrix_t.v[8] = cs * (izx) + sn * (i.y) + izx;
	matrix_t.v[9] = cs * (-iyz) + sn * (-i.x) + iyz;
	matrix_t.v[10] = cs * (1-iz2) + iz2;
	matrix_t.contact33(Matrix, matrix);
}

};


