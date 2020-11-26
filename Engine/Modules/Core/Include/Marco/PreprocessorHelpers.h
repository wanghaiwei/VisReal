/**
 * Created by rayfalling on 2020/11/9.
 * */

#pragma once

#ifndef VISREAL_PREPROCESSOR_HELPERS_H
#define VISREAL_PREPROCESSOR_HELPERS_H

namespace Engine::Core {
	// Turns an preprocessor token into a real string (see UBT_COMPILED_PLATFORM)
	#define PREPROCESSOR_TO_STRING(x) PREPROCESSOR_TO_STRING_INNER(x)
	#define PREPROCESSOR_TO_STRING_INNER(x) #x

	// Concatenates two preprocessor tokens, performing macro expansion on them first
	#define PREPROCESSOR_JOIN(x, y) PREPROCESSOR_JOIN_INNER(x, y)
	#define PREPROCESSOR_JOIN_INNER(x, y) x##y

	// Expands to the second argument or the third argument if the first argument is 1 or 0 respectively
	#define PREPROCESSOR_IF(cond, x, y) PREPROCESSOR_JOIN(PREPROCESSOR_IF_INNER_, cond)(x, y)
	#define PREPROCESSOR_IF_INNER_1(x, y) x
	#define PREPROCESSOR_IF_INNER_0(x, y) y

	// Expands to the parameter list of the macro - used for when you need to pass a comma-separated identifier to another macro as a single parameter
	#define PREPROCESSOR_COMMA_SEPARATED(first, second, ...) first, second, ##__VA_ARGS__

	// Expands to nothing - used as a placeholder
	#define PREPROCESSOR_NOTHING

	// setup standardized way of including platform headers from the "uber-platform" headers like PlatformFile.h
	#ifdef OVERRIDE_PLATFORM_HEADER_NAME
	// allow for an override, so compiled platforms Win64 and Win32 will both include Windows
	#define PLATFORM_HEADER_NAME OVERRIDE_PLATFORM_HEADER_NAME
	#else
	// otherwise use the compiled platform name
	#define PLATFORM_HEADER_NAME UBT_COMPILED_PLATFORM
	#endif

	#ifndef PLATFORM_IS_EXTENSION
	#define PLATFORM_IS_EXTENSION 0
	#endif

	#if PLATFORM_IS_EXTENSION
	// Creates a string that can be used to include a header in the platform extension form "PlatformHeader.h", not like below form
	#define COMPILED_PLATFORM_HEADER(Suffix) PREPROCESSOR_TO_STRING(PREPROCESSOR_JOIN(PLATFORM_HEADER_NAME, Suffix))
	#else
	// Creates a string that can be used to include a header in the form "Platform/PlatformHeader.h", like "Windows/WindowsPlatformFile.h"
	#define COMPILED_PLATFORM_HEADER(Suffix) PREPROCESSOR_TO_STRING(PREPROCESSOR_JOIN(Platform/PLATFORM_HEADER_NAME/PLATFORM_HEADER_NAME, Suffix))
	#endif

	#if PLATFORM_IS_EXTENSION
	// Creates a string that can be used to include a header with the platform in its name, like "Pre/Fix/PlatformNameSuffix.h"
	#define COMPILED_PLATFORM_HEADER_WITH_PREFIX(Prefix, Suffix) PREPROCESSOR_TO_STRING(Prefix/PREPROCESSOR_JOIN(PLATFORM_HEADER_NAME, Suffix))
	#else
	// Creates a string that can be used to include a header with the platform in its name, like "Pre/Fix/PlatformName/PlatformNameSuffix.h"
	#define COMPILED_PLATFORM_HEADER_WITH_PREFIX(Prefix, Suffix) PREPROCESSOR_TO_STRING(Prefix/PLATFORM_HEADER_NAME/PREPROCESSOR_JOIN(PLATFORM_HEADER_NAME, Suffix))
	#endif
}

#endif // VISREAL_PREPROCESSOR_HELPERS_H
