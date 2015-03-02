

#include "CGatherNode2d.h"
#include "CNodeCamera.h"

namespace engine{

CGatherNode2d::CGatherNode2d(view::IPlatform *platform)
	: CGatherNode(platform)
{
	Camera = new CNodeCamera();
}

};

