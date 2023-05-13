project('adhesive', ['c'],
  version : '0.1.0',
  default_options : [
    'warning_level=3',
    'werror=true',
    'b_sanitize=address,undefined,memory,thread',
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

libmicrodns = library('adhesive',
    src,
    include_directories: incdirs,
)
