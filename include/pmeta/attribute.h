/**
 * @file attribute.h
 * @brief Macros for testing existence of a language-specific or
 * compiler-specific attribute.
 */
#pragma once

#include <pmeta/standards.h>

/**
 * @def PMETA_HAS_BUILTIN
 * @brief Predicate whether the compiler supports a particular builtin function.
 */
#if defined(__has_builtin)
#    define PMETA_HAS_BUILTIN(x) __has_builtin(x)
#else
#    define PMETAPMETA_HAS_BUILTIN(_x) 0
#endif

/**
 * @def PMETA_HAS_ATTRIBUTE
 * @brief Predicate whether the compiler supports a particular attribute.
 */
#if defined(__has_attribute)
#    define PMETA_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
#    define PMETA_HAS_ATTRIBUTE(x) 0
#endif

/**
 * @def PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
 * @brief Predicate whether the language supports `[[...]]` syntax for
 * attributes.
 */
#if defined(__cplusplus) || PMETA_C_STD23
#    define PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES 1
#else
#    define PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES 1
#endif
