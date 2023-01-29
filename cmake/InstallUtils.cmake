include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

function(install_project TARGETS)
  cmake_parse_arguments(ITARGET "" HEADER_SUBDIR "" ${ARGN})

  if(DEFINED ITARGET_HEADER_SUBDIR)
    set(header_install_dir ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}/${ITARGET_HEADER_SUBDIR})
  else()
    set(header_install_dir ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME})
  endif()

  install(TARGETS ${TARGETS}
    EXPORT ${CMAKE_PROJECT_NAME}-export
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            COMPONENT  ${CMAKE_PROJECT_NAME}_Runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT          ${CMAKE_PROJECT_NAME}_Runtime
            NAMELINK_COMPONENT ${CMAKE_PROJECT_NAME}_Development
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT ${CMAKE_PROJECT_NAME}_Development
    PUBLIC_HEADER DESTINATION ${header_install_dir}
                COMPONENT ${CMAKE_PROJECT_NAME}_Development)

  install(EXPORT ${CMAKE_PROJECT_NAME}-export
    FILE ${CMAKE_PROJECT_NAME}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

  write_basic_package_version_file(${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/libConfig.cmake.in
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}
  )

  install(FILES
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
endfunction()
