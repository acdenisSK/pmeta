/**
 * @file platforms.hpp
 * @brief Set of macros for conditional compilation around specific platforms /
 * operating systems.
 */
#pragma once

#ifdef _WIN32
/**
 * @brief Shows whether the code is compiled on Windows.
 *
 * @details Use `#if PMETA_COMPILED_ON_WINDOWS` to compile code for Windows.
 */
#    define PMETA_COMPILED_ON_WINDOWS 1
#else
/**
 * @brief Shows whether the code is compiled on Windows.
 *
 * @details Use `#if PMETA_COMPILED_ON_WINDOWS` to compile code for Windows.
 */
#    define PMETA_COMPILED_ON_WINDOWS 0
#endif

#if defined(__linux__) && !defined(__ANDROID__)
/**
 * @brief Shows whether the code is compiled on Linux.
 *
 * @details Use `#if PMETA_COMPILED_ON_LINUX` to compile code for Linux.
 */
#    define PMETA_COMPILED_ON_LINUX 1
#else
/**
 * @brief Shows whether the code is compiled on Linux.
 *
 * @details Use `#if PMETA_COMPILED_ON_LINUX` to compile code for Linux.
 */
#    define PMETA_COMPILED_ON_LINUX 0
#endif

#ifdef __ANDROID__
/**
 * @brief Shows whether the code is compiled on Android.
 *
 * @details Use `#if PMETA_COMPILED_ON_ANDROID` to compile code for Android.
 */
#    define PMETA_COMPILED_ON_ANDROID 1
#else
/**
 * @brief Shows whether the code is compiled on Android.
 *
 * @details Use `#if PMETA_COMPILED_ON_ANDROID` to compile code for Android.
 */
#    define PMETA_COMPILED_ON_ANDROID 0
#endif

#ifdef __APPLE__
/**
 * @brief Shows whether the code is compiled on an Apple platform.
 *
 * @details Use `#if PMETA_COMPILED_ON_APPLE` to compile code for an Apple
 * platform.
 */
#    define PMETA_COMPILED_ON_APPLE 1
#else
/**
 * @brief Shows whether the code is compiled on an Apple platform.
 *
 * @details Use `#if PMETA_COMPILED_ON_APPLE` to compile code for an Apple
 * platform.
 */
#    define PMETA_COMPILED_ON_APPLE 0
#endif

/**
 * @brief Shows whether the code is compiled on a Unix platform.
 *
 * @details A "Unix" platform is considered to be Linux, Android, or Apple.
 * @details Use `#if PMETA_COMPILED_ON_UNIX` to compile code for a Unix
 * platform.
 */
#define PMETA_COMPILED_ON_UNIX                               \
    (PMETA_COMPILED_ON_LINUX || PMETA_COMPILED_ON_ANDROID || \
     PMETA_COMPILED_ON_APPLE)
