/**
 * @file standards.hpp
 * @brief Set of macros for conditional compilation around specific C++
 * standards.
 */
#pragma once

#if __cplusplus >= 201103L
/**
 * @brief Shows whether the C++11 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD11` to compile code for C++11
 */
#    define PMETA_CPP_STD11 1
#else
/**
 * @brief Shows whether the C++11 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD11` to compile code for C++11
 */
#    define PMETA_CPP_STD11 0
#endif

#if __cplusplus >= 201402L
/**
 * @brief Shows whether the C++14 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD14` to compile code for C++14
 */
#    define PMETA_CPP_STD14 1
#else
/**
 * @brief Shows whether the C++14 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD14` to compile code for C++14
 */
#    define PMETA_CPP_STD14 0
#endif

#if __cplusplus >= 201703L
/**
 * @brief Shows whether the C++17 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD17` to compile code for C++17
 */
#    define PMETA_CPP_STD17 1
#else
/**
 * @brief Shows whether the C++17 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD17` to compile code for C++17
 */
#    define PMETA_CPP_STD17 0
#endif

#if __cplusplus >= 202002L
/**
 * @brief Shows whether the C++20 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD20` to compile code for C++20
 */
#    define PMETA_CPP_STD20 1
#else
/**
 * @brief Shows whether the C++20 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD20` to compile code for C++20
 */
#    define PMETA_CPP_STD20 0
#endif

#if __cplusplus > 202002L
/**
 * @brief Shows whether the C++23 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD23` to compile code for C++23
 */
#    define PMETA_CPP_STD23 1
#else
/**
 * @brief Shows whether the C++23 standard is enabled.
 *
 * @details Use `#if PMETA_CPP_STD23` to compile code for C++23
 */
#    define PMETA_CPP_STD23 0
#endif
