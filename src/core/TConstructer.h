#ifndef __BASE_CONSTRUCTER_H__
#define __BASE_CONSTRUCTER_H__

#define __construct_global(__NAME__, __CODE__)		\
	static class __NAME__##_c_class{\
	public: __NAME__##_c_class(){\
		__CODE__;\
	}\
	} __NAME__##_c_instance

#define __destruct_global()		\
	static class __NAME__##_d_class{\
	public: ~__NAME__##_d_class(){\
		__CODE__;\
	}\
	} __NAME__##_d_instance

#endif

