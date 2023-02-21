/**
 * @file function.hpp
 * @brief Set of attributes for applying on a function.
 */
#pragma once

#include <pmeta/attribute.hpp>

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
