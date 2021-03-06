/**
 * Created by rayfalling on 2020/10/20.
 * */

#ifndef VISREAL_MSVC_PLATFORM_H
#define VISREAL_MSVC_PLATFORM_H

namespace Engine::Core {
	#if _MSC_FULL_VER >= 191125507 && defined(__cpp_if_constexpr)
	#define PLATFORM_COMPILER_HAS_IF_CONSTEXPR 1
	#else
    #define PLATFORM_COMPILER_HAS_IF_CONSTEXPR 0
	#endif

	#ifndef ENABLE_NAN_DIAGNOSTIC
	#ifndef NDEBUG
	#define ENABLE_NAN_DIAGNOSTIC 1
	#else
	#define ENABLE_NAN_DIAGNOSTIC 0
	#endif
	#endif
}

#endif //VISREAL_MSVC_PLATFORM_H
