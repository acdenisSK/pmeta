/**
 * @file function.hpp
 * @brief Set of attributes for applying on a function.
 */
#pragma once

#include <pmeta/attribute.hpp>
#include <pmeta/standards.hpp>

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
