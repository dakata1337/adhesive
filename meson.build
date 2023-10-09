project('adhesive', ['c'],
  version : '0.1.0',
  default_options : [
    'warning_level=3',
    'werror=true',
    'b_sanitize=address,undefined',
    'buildtype=release',
    'optimization=2',
  ]
)

warning_flags = [
    '-Wsign-compare',
    '-Wstrict-aliasing',
    '-Wstrict-overflow',
    '-Wformat=2',
    '-Wno-unused-parameter',
    '-Wcast-align',
    '-Wpointer-arith',
    '-Wwrite-strings',
    '-Wlogical-op',
]

cc = meson.get_compiler('c')
add_project_arguments(cc.get_supported_arguments(warning_flags), language: 'c')

incdirs = include_directories('./include')
src = [
    './src/string.c',
    './src/linked_list.c',
]

project_target = static_library(
    meson.project_name(),
    src,
    install: true,
    include_directories: incdirs,
)

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
    include_directories: incdirs,
    link_with: project_target
)
set_variable(meson.project_name() + '_dep', project_dep)
meson.override_dependency(meson.project_name(), project_dep)
