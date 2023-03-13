/**
 * @file layout.h
 * @brief Attributes relating to the memory layout of a type
 */
#pragma once

#include <pmeta/attribute.h>

/**
 * @def PMETA_ALIGNAS
 * @brief Manually specifies the alignment of a type based on `x`
 * @param x A power of two value for the alignment
 */
#ifdef __cplusplus
#    define PMETA_ALIGNAS(x) alignas(x)
#elif PMETA_HAS_ATTRIBUTE(aligned)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_ALIGNAS(x) [[gnu::aligned(x)]]
#    else
#        define PMETA_ALIGNAS(x) __attribute__((aligned(x)))
#    endif
#else
#    define PMETA_ALIGNAS(_x)
#endif

/**
 * @def PMETA_PACKED
 * @brief Defines a type without padding.
 */
#if PMETA_HAS_ATTRIBUTE(packed)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_PACKED [[gnu::packed]]
#    else
#        define PMETA_PACKED __attribute__((packed))
#    endif
#else
#    define PMETA_PACKED
#endif
