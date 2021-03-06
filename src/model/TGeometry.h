#ifndef __BASE_GEOMETRY_H__
#define __BASE_GEOMETRY_H__

#include <math.h>

namespace model{

	template<typename T>
	struct Point2d
	{
		T x, y;
		inline Point2d() : x(0), y(0){}
		inline Point2d(T _x, T _y) : x(_x), y(_y){}
		inline Point2d(const Point2d &copy) : x(copy.x), y(copy.y){}
	};

	template<typename T>
	struct Size2d
	{
		T w, h;
		inline Size2d() : w(0), h(0){}
		inline Size2d(T _w, T _h) : w(_w), h(_h){}
		inline Size2d(const Size2d &copy) : w(copy.w), h(copy.h){}
	};

	template<typename T>
	struct Rect2d
	{
		T x, y, w, h;
		inline Rect2d() : x(0), y(0), w(0), h(0){}
		inline Rect2d(T _x, T _y, T _w, T _h) : x(_x), y(_y), w(_w), h(_h){}
		inline Rect2d(const Point2d<T> &pt, const Size2d<T> &siz) : x(pt.x), y(pt.y), w(siz.w), h(siz.h){}
		inline Rect2d(const Rect2d &copy) : x(copy.x), y(copy.y), w(copy.w), h(copy.h){}
		inline Point2d<T> base(){return Point2d<T>(x, y);}
		inline Point2d<T> apart(){return Point2d<T>(x+w, y+h);}
		inline Size2d<T> size(){return Size2d<T>(w, h);}
	};

	template<typename T>
	struct Vector3d
	{
		T x, y, z;
		inline Vector3d() : x(0), y(0), z(0){}
		inline Vector3d(T _x, T _y, T _z) : x(_x), y(_y), z(_z){}
		inline Vector3d(const Vector3d &copy) : x(copy.x), y(copy.y), z(copy.z){}
		inline void normalize(){
			float a_len = sqrt(x*x + y*y + z*z);
			if (a_len <= 0){
				return ;
			}
			if (a_len != 1.0f){
				x /= a_len;
				y /= a_len;
				z /= a_len;
			}
		}
	};

	template<typename T>
	struct Volume3d
	{
		T w, h, d;
		inline Volume3d() : w(0), h(0), d(0){}
		inline Volume3d(T _w, T _h, T _d) : w(_w), h(_h), d(_d){}
		inline Volume3d(const Volume3d &copy) : w(copy.w), h(copy.h), d(copy.d){}
	};

	template<typename T>
	struct Bound3d
	{
		T x, y, z, w, h, d;
		inline Bound3d() : x(0), y(0), z(0), w(0), h(0), d(0){}
		inline Bound3d(T _x, T _y, T _z, T _w, T _h, T _d) : x(_x), y(_y), z(_z), w(_w), h(_h), d(_d){}
		inline Bound3d(const Vector3d<T> &vec, const Volume3d<T> &vol) : x(vec.x), y(vec.y), z(vec.z), w(vol.w), h(vol.h), d(vol.d){}
		inline Bound3d(const Bound3d &copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w), h(copy.h), d(copy.d){}
	};

	template<typename T>
	struct Color3ch
	{
		T r, g, b;
		Color3ch() : r(0), g(0), b(0){}
		Color3ch(T _r, T _g, T _b) : r(_r), g(_g), b(_b){}
	};

	template<typename T>
	struct Color4ch
	{
		T r, g, b, a;
		Color4ch() : r(0), g(0), b(0), a(1){}
		Color4ch(T _r, T _g, T _b, T _a) : r(_r), g(_g), b(_b), a(_a){}
		Color4ch(const Color3ch<T> &col) : r(col.r), g(col.g), b(col.b), a(1){}
	};

	typedef Point2d<int> Pointi;
	typedef Size2d<int> Sizei;
	typedef Rect2d<int> Recti;
	typedef Point2d<float> Pointf;
	typedef Size2d<float> Sizef;
	typedef Rect2d<float> Rectf;

	typedef Vector3d<int> Vectori;
	typedef Volume3d<int> Volumei;
	typedef Bound3d<int> Boundi;
	typedef Vector3d<float> Vectorf;
	typedef Volume3d<float> Volumef;
	typedef Bound3d<float> Boundf;

	typedef Color3ch<float> Color3f;
	typedef Color3ch<double> Color3d;
	typedef Color4ch<float> Color4f;
	typedef Color4ch<double> Color4d;
	
};

#endif

