cmake_minimum_required(VERSION 3.14)
project(pmeta
  VERSION 0.1.0
  DESCRIPTION "C++ preprocessor metaprogramming library"
  HOMEPAGE_URL "https://github.com/acdenisSK/pmeta"
  LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)
include(InstallUtils)
include(ClangFormat)

option(PMETA_BUILD_DOCS "Build documentation" OFF)

add_subdirectory(src)

install_project(pmeta)

if(PMETA_BUILD_DOCS)
  add_subdirectory(docs)
endif()
