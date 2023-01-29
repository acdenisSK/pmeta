cmake_minimum_required(VERSION 3.13)
project(pmeta
  VERSION 0.0.1
  DESCRIPTION "C++ preprocessor metaprogramming library"
  HOMEPAGE_URL "https://github.com/acdenisSK/pmeta"
  LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)
include(InstallUtils)
include(ClangFormat)

option(PMETA_BUILD_DOCS "Build documentation" OFF)

set(headers
  include/pmeta/attributes.hpp
  include/pmeta/compilers.hpp
  include/pmeta/platforms.hpp
  include/pmeta/standards.hpp
)

add_library(pmeta INTERFACE ${headers})
target_sources(pmeta PRIVATE ${headers})

target_compile_features(pmeta INTERFACE cxx_std_11)
set_target_properties(pmeta PROPERTIES
  CXX_EXTENSIONS OFF
  VERSION ${CMAKE_PROJECT_VERSION}
  PUBLIC_HEADER "${headers}")

target_include_directories(pmeta INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

add_library(pmeta::pmeta ALIAS pmeta)

install_project(pmeta)

target_clangformat_setup(pmeta)

if(PMETA_BUILD_DOCS)
  add_subdirectory(docs)
endif()
