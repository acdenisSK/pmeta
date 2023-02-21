/**
 * @file attribute.hpp
 * @brief Set of macros for testing existence of a C++ or compiler-specific
 * attribute.
 */
#pragma once

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
