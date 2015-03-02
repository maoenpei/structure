#ifndef __BASE_ATTRIB_DATA_H__
#define __BASE_ATTRIB_DATA_H__

namespace engine{

	template<class T>
	struct POS2D
	{
		T x, y;
	};

	template<class T>
	struct POS3D
	{
		T x, y, z;
	};

	template<class T>
	struct TEX2D
	{
		T u, v;
	};

	template<class T>
	struct COLOR3
	{
		T r, g, b;
	};

	template<class T>
	struct COLOR4
	{
		T r, g, b, a;
	};
	
};

#endif

