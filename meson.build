project('pmeta', 'cpp',
  version : '0.2.0',
  license : 'BSL-1.0',
)

pkgconfig = import('pkgconfig')

prefix = get_option('prefix')
includedir = prefix / get_option('includedir')

inc = include_directories('include')

# Header-only libraries

## pmeta
pmeta_dep = declare_dependency(
  include_directories : inc,
)

install_subdir('include/pmeta', install_dir : includedir)
##

#

pkgconfig.generate(
  name : 'pmeta',
  description : 'Header-only library for the preprocessor used by the C and C++ languages',
  url : 'https://github.com/acdenisSK/pmeta',
  version : meson.project_version(),
)

if get_option('docs')
  subdir('docs')
endif
