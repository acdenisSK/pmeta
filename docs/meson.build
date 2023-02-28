doxy = find_program('doxygen', required : true)
sphinx = find_program('sphinx-build', required : true)

docdir = prefix / get_option('datadir') / 'doc' / meson.project_name()

version = meson.project_version()
version_chunks = version.split('.')
version_major = version_chunks[0]
version_minor = version_chunks[1]
version_patch = version_chunks[2]

config = configuration_data()
config.set('PROJECT_NAME', meson.project_name())
config.set('PROJECT_VERSION_MAJOR', version_major)
config.set('PROJECT_VERSION_MINOR', version_minor)
config.set('PROJECT_VERSION_PATCH', version_patch)
config.set('SOURCE_ROOT', meson.global_source_root())
config.set('BUILD_ROOT', meson.global_build_root())

doxyfile = configure_file(
  input : files('Doxyfile.in'),
  output : 'Doxyfile',
  configuration : config,
  install : false,
)

docs_srcs = files(
  'index.rst',
  'license.rst',
  'conf.py',
)

docs = custom_target('docs',
  input : [doxyfile] + docs_srcs,
  output : ['html'],
  command : [doxy, doxyfile],
  install : true,
  install_dir : docdir,
)

custom_target('sphinx',
  command : [
    sphinx,
    '-b', 'html',
    '-Dbreathe_projects.@0@=@1@/docs/xml'.format(meson.project_name(), meson.global_build_root()),
    '@0@/docs'.format(meson.global_source_root()),
    '@0@/docs/sphinx'.format(meson.global_build_root()),
  ],
  output : ['sphinx'],
  depends : docs,
  install : true,
  install_dir : docdir,
)
