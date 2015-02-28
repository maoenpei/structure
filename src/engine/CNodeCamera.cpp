

#include "CNodeCamera.h"
#include <math.h>

namespace engine{

void CNodeCamera::dispose(graphics::ITransformer * trans)
{
	trans->contact(Affine);
}

void CNodeCamera::identity()
{
	Affine = graphics::TAffinef();
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
	Affine.v[4] *= sx;
	Affine.v[5] *= sy;
}

void CNodeCamera::rotate(float sita)
{
	graphics::TAffinef aff(Affine);
	float sn = sin(sita);
	float cs = cos(sita);

	Affine.v[0] = aff.v[0] * cs - aff.v[1] * sn;
	Affine.v[1] = aff.v[0] * sn + aff.v[1] * cs;
	Affine.v[2] = aff.v[2] * cs - aff.v[3] * sn;
	Affine.v[3] = aff.v[2] * sn + aff.v[3] * cs;
	Affine.v[4] = aff.v[4] * cs - aff.v[5] * sn;
	Affine.v[5] = aff.v[4] * sn + aff.v[5] * cs;
}

};
