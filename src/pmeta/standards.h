/**
 * @file standards.h
 * @brief Set of macros for conditional compilation around specific C and C++
 * standards.
 */
#pragma once

/**
 * @def PMETA_C_STD98
 * @brief Shows whether the C98 standard is enabled.
 *
 * @details Use `#if PMETA_C_STD98` to compile code for C98
 */

/**
 * @def PMETA_C_STD11
 * @brief Shows whether the C11 standard is enabled.
 *
 * @details Use `#if PMETA_C_STD11` to compile code for C11
 */

/**
 * @def PMETA_C_STD17
 * @brief Shows whether the C17 standard is enabled.
 *
 * @details Use `#if PMETA_C_STD17` to compile code for C17
 */

/**
 * @def PMETA_C_STD23
 * @brief Shows whether the C23 standard is enabled.
 *
 * @details Use `#if PMETA_C_STD23` to compile code for C23
 */

#ifdef __STDC_VERSION__
#    if __STDC_VERSION__ >= 199901L
#        define PMETA_C_STD98 1
#    else
#        define PMETA_C_STD98 0
#    endif
#    if __STDC_VERSION__ >= 201112L
#        define PMETA_C_STD11 1
#    else
#        define PMETA_C_STD11 0
#    endif
#    if __STDC_VERSION__ >= 201710L
#        define PMETA_C_STD17 1
#    else
#        define PMETA_C_STD17 0
#    endif
#    if __STDC_VERSION__ > 201710L
#        define PMETA_C_STD23 1
#    else
#        define PMETA_C_STD23 0
#    endif
#else
#    define PMETA_C_STD98 0
#    define PMETA_C_STD11 0
#    define PMETA_C_STD17 0
#    define PMETA_C_STD23 0
#endif

/**
 * @def PMETA_CPP_STD11
 * @brief Shows whether the C++11 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD11` to compile code for C++11
 */

/**
 * @def PMETA_CPP_STD14
 * @brief Shows whether the C++14 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD14` to compile code for C++14
 */

/**
 * @def PMETA_CPP_STD17
 * @brief Shows whether the C++17 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD17` to compile code for C++17
 */

/**
 * @def PMETA_CPP_STD20
 * @brief Shows whether the C++20 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD20` to compile code for C++20
 */

/**
 * @def PMETA_CPP_STD23
 * @brief Shows whether the C++23 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD23` to compile code for C++23
 */

#ifdef __cplusplus
#    if __cplusplus >= 201103L
#        define PMETA_CPP_STD11 1
#    else
#        define PMETA_CPP_STD11 0
#    endif
#    if __cplusplus >= 201402L
#        define PMETA_CPP_STD14 1
#    else
#        define PMETA_CPP_STD14 0
#    endif
#    if __cplusplus >= 201703L
#        define PMETA_CPP_STD17 1
#    else
#        define PMETA_CPP_STD17 0
#    endif
#    if __cplusplus >= 202002L
#        define PMETA_CPP_STD20 1
#    else
#        define PMETA_CPP_STD20 0
#    endif
#    if __cplusplus > 202002L
#        define PMETA_CPP_STD23 1
#    else
#        define PMETA_CPP_STD23 0
#    endif
#else
#    define PMETA_CPP_STD11 0
#    define PMETA_CPP_STD14 0
#    define PMETA_CPP_STD17 0
#    define PMETA_CPP_STD20 0
#    define PMETA_CPP_STD23 0
#endif
