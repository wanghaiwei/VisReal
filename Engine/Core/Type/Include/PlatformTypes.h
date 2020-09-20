//
// Created by rayfalling on 2020/8/29.
//
#pragma once

#ifndef VISREAL_PLATFORM_TYPES_H
#define VISREAL_PLATFORM_TYPES_H

#ifdef MSVC
// include windows platform types
#include "WindowsPlatform.h"

#endif

using namespace Engine::Core::Types;

//~ Unsigned base types.
/// An 8-bit unsigned integer.
typedef FPlatformTypes::uint8  uint8;
/// A 16-bit unsigned integer.
typedef FPlatformTypes::uint16 uint16;
/// A 32-bit unsigned integer.
typedef FPlatformTypes::uint32 uint32;
/// A 64-bit unsigned integer.
typedef FPlatformTypes::uint64 uint64;

//~ Signed base types.
/// An 8-bit signed integer.
typedef FPlatformTypes::int8  int8;
/// A 16-bit signed integer.
typedef FPlatformTypes::int16 int16;
/// A 32-bit signed integer.
typedef FPlatformTypes::int32 int32;
/// A 64-bit signed integer.
typedef FPlatformTypes::int64 int64;

//~ Character types.
/// An ANSI character. Normally a signed type.
typedef FPlatformTypes::CHAR   CHAR;
/// A wide character. Normally a signed type.
typedef FPlatformTypes::WCHAR  WCHAR;
/// Either CHAR or WCHAR, depending on whether the platform supports wide characters or the requirements of the licensee.
typedef FPlatformTypes::TCHAR  TCHAR;
/// An 8-bit character containing a UTF8 (Unicode, 8-bit, variable-width) code unit.
typedef FPlatformTypes::CHAR8  UTF8CHAR;
/// A 16-bit character containing a UCS2 (Unicode, 16-bit, fixed-width) code unit, used for compatibility with 'Windows TCHAR' across multiple platforms.
typedef FPlatformTypes::CHAR16 UCS2CHAR;
/// A 16-bit character containing a UTF16 (Unicode, 16-bit, variable-width) code unit.
typedef FPlatformTypes::CHAR16 UTF16CHAR;
/// A 32-bit character containing a UTF32 (Unicode, 32-bit, fixed-width) code unit.
typedef FPlatformTypes::CHAR32 UTF32CHAR;

/// An unsigned integer the same size as a pointer
typedef FPlatformTypes::UPTR_SIZE UPTR_SIZE;
/// A signed integer the same size as a pointer
typedef FPlatformTypes::PTR_SIZE  PTR_SIZE;
/// An unsigned integer the same size as a pointer, the same as UPTR_SIZE
typedef FPlatformTypes::USIZE_T   USIZE_T;
/// An integer the same size as a pointer, the same as PTR_SIZE
typedef FPlatformTypes::SIZE_T    SIZE_T;

#endif //VISREAL_PLATFORM_TYPES_H
