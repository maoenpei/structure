#ifndef __BASE_IREF_H__
#define __BASE_IREF_H__

#ifdef WIN32
#pragma warning(disable:4250)
#endif

namespace core{

	class IRef
	{
	public:
		virtual IRef * grab() = 0;
		virtual IRef * drop() = 0;

		template<class I>
		inline I *cast(){return dynamic_cast<I *>(this);}
	};
	
};

#endif

