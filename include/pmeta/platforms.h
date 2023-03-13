/**
 * @file platforms.h
 * @brief Set of macros for conditional compilation around specific platforms /
 * operating systems.
 */
#pragma once

/**
 * @def PMETA_COMPILED_ON_WINDOWS
 * @brief Shows whether the code is compiled on Windows.
 *
 * @details Use `#if PMETA_COMPILED_ON_WINDOWS` to compile code for Windows.
 */
#ifdef _WIN32
#    define PMETA_COMPILED_ON_WINDOWS 1
#else
#    define PMETA_COMPILED_ON_WINDOWS 0
#endif

/**
 * @def PMETA_COMPILED_ON_LINUX
 * @brief Shows whether the code is compiled on Linux.
 *
 * @details Use `#if PMETA_COMPILED_ON_LINUX` to compile code for Linux.
 */
#if defined(__linux__) && !defined(__ANDROID__)
#    define PMETA_COMPILED_ON_LINUX 1
#else
#endif

/**
 * @def PMETA_COMPILED_ON_ANDROID
 * @brief Shows whether the code is compiled on Android.
 *
 * @details Use `#if PMETA_COMPILED_ON_ANDROID` to compile code for Android.
 */
#ifdef __ANDROID__
#    define PMETA_COMPILED_ON_ANDROID 1
#else
#    define PMETA_COMPILED_ON_ANDROID 0
#endif

/**
 * @def PMETA_COMPILED_ON_APPLE
 * @brief Shows whether the code is compiled on an Apple platform.
 *
 * @details Use `#if PMETA_COMPILED_ON_APPLE` to compile code for an Apple
 * platform.
 */
#ifdef __APPLE__
#    define PMETA_COMPILED_ON_APPLE 1
#else
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
