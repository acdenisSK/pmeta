include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Install specific headers while retaining their directory structure
#
# # Usage
#
# ```cmake
# set(HEADERS
#   abc.h
#   def/ghi.h
# )
#
# install_headers(FILES ${HEADERS})
# # abc.h gets installed to `${CMAKE_INSTALL_INCLUDEDIR}/abc.h`
# # ghi.h gets installed to `${CMAKE_INSTALL_INCLUDEDIR}/def/ghi.h`
# ```
function(install_headers)
  ## Utility by user "Ad N" on Stack Overflow
  # https://stackoverflow.com/a/56261784
  set(optionsArgs "")
  set(oneValueArgs "DESTINATION")
  set(multiValueArgs "FILES")
  cmake_parse_arguments(CAS "${optionsArgs}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  if(NOT DEFINED CAS_DESTINATION)
    set(CAS_DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  endif()

  foreach(FILE ${CAS_FILES})
      get_filename_component(DIR ${FILE} DIRECTORY)
      INSTALL(FILES ${FILE} DESTINATION ${CAS_DESTINATION}/${DIR} COMPONENT ${CMAKE_PROJECT_NAME}_Development)
  endforeach()
endfunction()

function(install_project TARGETS)
  install(TARGETS ${TARGETS}
    EXPORT ${CMAKE_PROJECT_NAME}-export
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            COMPONENT  ${CMAKE_PROJECT_NAME}_Runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT          ${CMAKE_PROJECT_NAME}_Runtime
            NAMELINK_COMPONENT ${CMAKE_PROJECT_NAME}_Development
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT ${CMAKE_PROJECT_NAME}_Development)

  install(EXPORT ${CMAKE_PROJECT_NAME}-export
    FILE ${CMAKE_PROJECT_NAME}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/${CMAKE_PROJECT_NAME})

  write_basic_package_version_file(${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/libConfig.cmake.in
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION
    ${CMAKE_INSTALL_DATADIR}/cmake/${CMAKE_PROJECT_NAME}
  )

  install(FILES
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/${CMAKE_PROJECT_NAME})
endfunction()
