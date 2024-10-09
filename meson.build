project(
  'sdl-gamescope-1521',
  'cpp',
  default_options: [
    'default_library=static',
    'cpp_std=c++20',
  ]
)

cpp = meson.get_compiler('cpp')

compiler_args = [
  '-m64',
]

linker_args = [
  '-m64',
]

add_project_arguments(cpp.get_supported_arguments(compiler_args), language: 'cpp')
add_project_link_arguments(cpp.get_supported_link_arguments(linker_args), language: 'cpp')

sdl_dep = dependency('sdl2', include_type: 'system')
src = files(['main.cpp'])

executable('sdl-gamescope-1521', src,
  dependencies: sdl_dep,
)

