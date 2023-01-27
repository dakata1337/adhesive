project('adhesive', 'c', version: '0.1.0',
  default_options: [
    'warning_level=3',
    'werror=true',
  ]
)

sources = [
  'src/linked_list.c'
]
includes = include_directories('include')

project_target = static_library(
  meson.project_name(),
  sources,
  install: true,
  include_directories: includes,
)

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
  include_directories: includes,
  link_with : project_target
)
set_variable(meson.project_name() + '_dep', project_dep)
meson.override_dependency(meson.project_name(), project_dep)

install_headers([], subdir: meson.project_name())

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name: meson.project_name(),
  filebase: meson.project_name(),
  description: 'A simple (not freestanding) library that implements some basic features',
  subdirs: meson.project_name(),
)
