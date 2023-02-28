/**
 * @file constexpr.hpp
 * @brief Set of macros for conditionally including support for C++'s
 * `constexpr`
 */
#pragma once

#include <pmeta/standards.h>

#if PMETA_CPP_STD11
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++11 support.
 *
 * @details If below C++11, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_11 constexpr
#else
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++11 support.
 *
 * @details If below C++11, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_11 inline
#endif

#if PMETA_CPP_STD14
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++14 support.
 *
 * @details If C++11 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_14 constexpr
#else
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++14 support.
 *
 * @details If C++11 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_14 inline
#endif

#if PMETA_CPP_STD17
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++17 support.
 *
 * @details If C++14 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_17 constexpr
#else
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++17 support.
 *
 * @details If C++14 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_17 inline
#endif

#if PMETA_CPP_STD20
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++20 support.
 *
 * @details If C++17 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_20 constexpr
#else
/**
 * @brief Function attribute. Marks a function as `constexpr` when compiled with
 * C++20 support.
 *
 * @details If C++17 or below, this will use `inline`.
 */
#    define PMETA_CONSTEXPR_20 inline
#endif
