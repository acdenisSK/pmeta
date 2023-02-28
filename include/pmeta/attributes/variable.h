/**
 * @file variable.h
 * @brief Set of attributes for applying on a variable.
 */
#pragma once

#include <pmeta/attribute.h>
#include <pmeta/standards.h>

/**
 * @def PMETA_UNUSED
 * @brief Variable attribute. Marks a variable as "unused", making it okay to
 * ignore using the variable.
 */
#if PMETA_HAS_ATTRIBUTE(maybe_unused) && (PMETA_CPP_STD17 || PMETA_C_STD23)
#    define PMETA_UNUSED [[maybe_unused]]
#elif PMETA_HAS_ATTRIBUTE(unused)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_UNUSED [[gnu::unused]]
#    else
#        define PMETA_UNUSED __attribute__((unused))
#    endif
#else
#    define PMETA_UNUSED
#endif
