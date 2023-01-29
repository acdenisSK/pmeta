find_package(Doxygen REQUIRED)

configure_file(
  ${PROJECT_SOURCE_DIR}/docs/Doxyfile.in
  ${PROJECT_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(docs
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM
)

find_package(Sphinx REQUIRED)

add_custom_target(
    sphinx
    COMMAND
    ${SPHINX_EXECUTABLE} -b html -Dbreathe_projects.${CMAKE_PROJECT_NAME}=${PROJECT_BINARY_DIR}/docs/xml
    ${PROJECT_SOURCE_DIR}/docs ${PROJECT_BINARY_DIR}/docs/sphinx
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/docs
    COMMENT "Generating documentation with Sphinx"
    VERBATIM
)

add_dependencies(sphinx docs)
