cmake_minimum_required(VERSION 3.14)
project(pmeta
  VERSION 0.1.0
  DESCRIPTION "C and C++ preprocessor metaprogramming library"
  HOMEPAGE_URL "https://github.com/acdenisSK/pmeta"
  LANGUAGES C CXX
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(InstallUtils)

option(PMETA_BUILD_DOCS "Build documentation" OFF)

add_subdirectory(src)

utils_install_project()

if(PMETA_BUILD_DOCS)
  add_subdirectory(docs)
endif()
