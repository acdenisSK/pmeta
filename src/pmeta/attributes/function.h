/**
 * @file function.h
 * @brief Set of attributes for applying on a function.
 */
#pragma once

#include <pmeta/attribute.h>

/**
 * @def PMETA_COLD
 * @brief Function attribute. Marks a function as "cold", which is unlikely to
 * be called often.
 */
#if PMETA_HAS_ATTRIBUTE(cold)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_COLD [[gnu::cold]]
#    else
#        define PMETA_COLD __attribute__((cold))
#    endif
#else
#    define PMETA_COLD
#endif

/**
 * @def PMETA_NORETURN
 * @brief Function attribute. Marks a function as an exit point of current
 * control flow.
 */
#if PMETA_HAS_ATTRIBUTE(noreturn)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_NORETURN [[noreturn]]
#    else
#        define PMETA_NORETURN __attribute__((noreturn))
#    endif
#else
#    define PMETA_NORETURN
#endif
