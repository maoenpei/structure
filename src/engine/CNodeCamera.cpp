

#include "CNodeCamera.h"
#include <math.h>

namespace engine{

void CNodeCamera::dispose(graphics::ITransformer * trans)
{
	trans->contact(Affine);
}

void CNodeCamera::identity()
{
	Affine.identity();
}

void CNodeCamera::move(float mx,float my)
{
	Affine.v[4] += mx;
	Affine.v[5] += my;
}

void CNodeCamera::scale(float sx,float sy)
{
	Affine.v[0] *= sx;
	Affine.v[1] *= sy;
	Affine.v[2] *= sx;
	Affine.v[3] *= sy;
}

void CNodeCamera::rotate(float sita)
{
	graphics::TAffinef aff(Affine);
	float sn = sin(sita);
	float cs = cos(sita);

	Affine.v[0] = cs * aff.v[0] - sn * aff.v[1];
	Affine.v[1] = sn * aff.v[0] + cs * aff.v[1];
	Affine.v[2] = cs * aff.v[2] - sn * aff.v[3];
	Affine.v[3] = sn * aff.v[2] + cs * aff.v[3];
}

};

