#ifndef __BASE_AUTO_H__
#define __BASE_AUTO_H__

namespace core{

	template<class I>
	class TAuto
	{
		I *ptr;
	public:
		inline TAuto() : ptr(0){}
		inline TAuto(I *_ptr) : ptr(_ptr){if (ptr) ptr->grab();}
		inline TAuto(const TAuto &copy) : ptr(copy.ptr){if (ptr) ptr->grab();}
		inline ~TAuto(){if (ptr) ptr->drop();}

		inline TAuto &operator =(I *_ptr){
			if (_ptr) _ptr->grab();
			if (ptr) ptr->drop();
			ptr = _ptr;
			return *this;
		}
		inline operator I*() const{return ptr;}
		inline I *operator ->() const{return ptr;}
		inline bool operator ==(I *_ptr) const{return ptr == _ptr;}
		inline bool operator !=(I *_ptr) const{return ptr != _ptr;}
		template<class II>
		inline II *cast() const{return dynamic_cast<II *>(ptr);}
	};
	
};

#endif

