/**
 * @file compilers.hpp
 * @brief Set of macros for conditional programming around specific compilers.
 */
#pragma once

#ifdef _MSC_VER
/**
 * @brief Shows whether the code is compiled with the MSVC/Visual Studio
 * compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_MSVC` to compile code for the MSVC compiler.
 */
#    define PMETA_COMPILED_WITH_MSVC 1
#else
/**
 * @brief Shows whether the code is compiled with the MSVC/Visual Studio
 * compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_MSVC` to compile code for the MSVC compiler.
 */
#    define PMETA_COMPILED_WITH_MSVC 0
#endif

#ifdef __GNUC__
/**
 * @brief Shows whether the code is compiled with the GNU (g++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_GNU` to compile code for the GNU compiler.
 */
#    define PMETA_COMPILED_WITH_GNU 1
#else
/**
 * @brief Shows whether the code is compiled with the GNU (g++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_GNU` to compile code for the GNU compiler.
 */
#    define PMETA_COMPILED_WITH_GNU 0
#endif

#ifdef __MINGW32__
/**
 * @brief Shows whether the code is compiled with the MINGW (g++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_MINGW` to compile code for the MINGW compiler.
 */
#    define PMETA_COMPILED_WITH_MINGW 1
#else
/**
 * @brief Shows whether the code is compiled with the MINGW (g++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_MINGW` to compile code for the MINGW compiler.
 */
#    define PMETA_COMPILED_WITH_MINGW 0
#endif

#ifdef __clang__
/**
 * @brief Shows whether the code is compiled with the LLVM (clang++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_CLANG` to compile code for the LLVM compiler.
 */
#    define PMETA_COMPILED_WITH_CLANG 1
#else
/**
 * @brief Shows whether the code is compiled with the LLVM (clang++) compiler.
 *
 * Use `#if PMETA_COMPILED_WITH_CLANG` to compile code for the LLVM compiler.
 */
#    define PMETA_COMPILED_WITH_CLANG 0
#endif
