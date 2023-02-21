set(headers
  pmeta/attributes/function.hpp
  pmeta/attributes/variable.hpp
  pmeta/attribute.hpp
  pmeta/compilers.hpp
  pmeta/constexpr.hpp
  pmeta/platforms.hpp
  pmeta/standards.hpp
)

add_library(pmeta INTERFACE)
add_library(pmeta::pmeta ALIAS pmeta)

target_sources(pmeta PRIVATE ${headers})

target_include_directories(pmeta INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install_headers(FILES ${headers})

target_clangformat_setup(pmeta)
