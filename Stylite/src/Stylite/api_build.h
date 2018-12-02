#pragma once
#ifdef SL_PLATFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define STYLITE_API __declspec(dllexport)
	#else
		#define STYLITE_API __declspec(dllimport)
	#endif // !SL_BUILD_DLL
#endif // !SL_PLATFORM_WINDOWS