#pragma once

#ifdef YU_PLATFORM_WINDOWS
	#ifdef YU_BUILD_DLL
		#define YUNA_API __declspec(dllexport)
	#else
		#define YUNA_API __declspec(dllimport)
	#endif // YU_BUILD_DLL
#else
	#error Yuna only supports Windows!
#endif // YU_PLATFORM_WINDOWS