/**
 * @file export.h
 * @brief Utility macros for defining symbol visibility.
 */
#pragma once

#include <pmeta/attribute.h>
#include <pmeta/compilers.h>
#include <pmeta/platforms.h>

/**
 * @def PMETA_EXPORT
 * @brief Exports a symbol of a type, making it available for dynamic linkage.
 */
#if PMETA_COMPILED_ON_WINDOWS
#    if PMETA_COMPILED_WITH_MSVC
#        define PMETA_EXPORT __declspec(dllexport)
#    elif PMETA_HAS_ATTRIBUTE(dllexport)
#        if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#            define PMETA_EXPORT [[gnu::dllexport]]
#        else
#            define PMETA_EXPORT __attribute__((dllexport))
#        endif
#    else
#        define PMETA_EXPORT
#    endif
#elif PMETA_HAS_ATTRIBUTE(visibility)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_EXPORT [[gnu::visibility("default")]]
#    else
#        define PMETA_EXPORT __attribute__((visibility("default")))
#    endif
#else
#    define PMETA_EXPORT
#endif

/**
 * @def PMETA_IMPORT
 * @brief Imports a symbol of a type for the purposes of dynamic linkage.
 */
#if PMETA_COMPILED_ON_WINDOWS
#    if PMETA_COMPILED_WITH_MSVC
#        define PMETA_IMPORT __declspec(dllimport)
#    elif PMETA_HAS_ATTRIBUTE(dllimport)
#        if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#            define PMETA_IMPORT [[gnu::dllimport]]
#        else
#            define PMETA_IMPORT __attribute__((dllimport))
#        endif
#    else
#        define PMETA_IMPORT
#    endif
#elif PMETA_HAS_ATTRIBUTE(visibility)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_IMPORT [[gnu::visibility("default")]]
#    else
#        define PMETA_IMPORT __attribute__((visibility("default")))
#    endif
#else
#    define PMETA_IMPORT
#endif

/**
 * @def PMETA_HIDE
 * @brief Hides a symbol of a type, making it unavailable for dynamic linkage.
 */
#if PMETA_COMPILED_ON_WINDOWS
// Default on Windows.
#    define PMETA_HIDE
#elif PMETA_HAS_ATTRIBUTE(visibility)
#    if PMETA_SUPPORTS_LANGUAGE_ATTRIBUTES
#        define PMETA_HIDE [[gnu::visibility("hidden")]]
#    else
#        define PMETA_HIDE __attribute__((visibility("hidden")))
#    endif
#else
#    define PMETA_HIDE
#endif
