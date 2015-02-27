#ifndef __BASE_AUTO_H__
#define __BASE_AUTO_H__

namespace core{

	template<typename I>
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
		inline TAuto &operator =(const TAuto &copy){
			if (copy.ptr) copy.ptr->grab();
			if (ptr) ptr->drop();
			ptr = copy.ptr;
			return *this;
		}
		inline I &operator *(){
			return *ptr;
		}
		inline operator I*() const{return ptr;}
		inline I *operator ->() const{return ptr;}
		inline bool operator ==(I *_ptr) const{return ptr == _ptr;}
		inline bool operator !=(I *_ptr) const{return ptr != _ptr;}
		template<typename II>
		inline II *cast() const{return dynamic_cast<II *>(ptr);}
	};
	
};

#endif

