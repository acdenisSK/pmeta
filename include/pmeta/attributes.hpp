/**
 * @file attributes.hpp
 * @brief Set of macros for C++ and compiler-specific attributes.
 */
#pragma once

#include <pmeta/standards.hpp>

#if defined(__has_attribute)
/**
 * @brief Predicate whether the compiler supports a particular attribute.
 */
#    define PMETA_HAS_COMPILER_ATTRIBUTE(x) __has_attribute(x)
#else
/**
 * @brief Predicate whether the compiler supports a particular attribute.
 */
#    define PMETA_HAS_COMPILER_ATTRIBUTE(x) 0
#endif

#if defined(__has_cpp_attribute)
/**
 * @brief Predicate whether the compiler supports a particular C++ attribute.
 */
#    define PMETA_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
/**
 * @brief Predicate whether the compiler supports a particular C++ attribute.
 */
#    define PMETA_HAS_CPP_ATTRIBUTE(x) 0
#endif

/**
 * @brief Predicate whether the compiler supports a particular attribute,
 * regardless of C++ exclusivity.
 */
#define PMETA_HAS_ATTRIBUTE(x) \
    (PMETA_HAS_CPP_ATTRIBUTE(x) || PMETA_HAS_COMPILER_ATTRIBUTE(x))

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

#if PMETA_HAS_CPP_ATTRIBUTE(cold)
/**
 * @brief Function attribute. Marks a function as "cold", which is unlikely to
 * be called often.
 */
#    define PMETA_COLD [[gnu::cold]]
#elif PMETA_HAS_COMPILER_ATTRIBUTE(cold)
/**
 * @brief Function attribute. Marks a function as "cold", which is unlikely to
 * be called often.
 */
#    define PMETA_COLD __attribute__((cold))
#else
/**
 * @brief Function attribute. Marks a function as "cold", which is unlikely to
 * be called often.
 */
#    define PMETA_COLD
#endif

#if PMETA_HAS_CPP_ATTRIBUTE(maybe_unused) && PMETA_CPP_STD17
/**
 * @brief Variable attribute. Marks a variable as "unused", making it okay to
 * ignore using the variable.
 */
#    define PMETA_UNUSED [[maybe_unused]]
#elif PMETA_HAS_CPP_ATTRIBUTE(unused)
/**
 * @brief Variable attribute. Marks a variable as "unused", making it okay to
 * ignore using the variable.
 */
#    define PMETA_UNUSED [[gnu::unused]]
#elif PMETA_HAS_COMPILER_ATTRIBUTE(unused)
/**
 * @brief Variable attribute. Marks a variable as "unused", making it okay to
 * ignore using the variable.
 */
#    define PMETA_UNUSED __attribute__((unused))
#else
/**
 * @brief Variable attribute. Marks a variable as "unused", making it okay to
 * ignore using the variable.
 */
#    define PMETA_UNUSED
#endif
