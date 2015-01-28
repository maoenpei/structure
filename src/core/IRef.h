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
	};
	
};

#endif

