project(
  'wlr-glew-renderer', 'c',
  version: '0.15.1.1',
  license: 'MIT',
  meson_version: '>=0.58.1',
  default_options: [
    'c_std=c11',
    'warning_level=2',
    'werror=true',
  ],
)

little_endian = host_machine.endian() == 'little'
big_endian = host_machine.endian() == 'big'

add_project_arguments([
	'-DWLR_USE_UNSTABLE',
	'-DWLR_LITTLE_ENDIAN=@0@'.format(little_endian.to_int()),
	'-DWLR_BIG_ENDIAN=@0@'.format(big_endian.to_int()),
  '-fvisibility=hidden',
], language: 'c')

cc = meson.get_compiler('c')

add_project_arguments(cc.get_supported_arguments([
  '-Wundef',
  '-Wlogical-op',
  '-Wmissing-include-dirs',
  '-Wold-style-definition',
  '-Wpointer-arith',
  '-Winit-self',
  '-Wstrict-prototypes',
  '-Wimplicit-fallthrough=2',
  '-Wendif-labels',
  '-Wstrict-aliasing=2',
  '-Woverflow',
  '-Wmissing-prototypes',
  '-Walloca',

  '-Wno-missing-braces',
  '-Wno-missing-field-initializers',
  '-Wno-unused-parameter',
]), language: 'c')

# Compute the relative path used by compiler invocations.
source_root = meson.current_source_dir().split('/')
build_root = meson.global_build_root().split('/')
relative_dir_parts = []
i = 0
in_prefix = true
foreach p : build_root
	if i >= source_root.length() or not in_prefix or p != source_root[i]
		in_prefix = false
		relative_dir_parts += '..'
	endif
	i += 1
endforeach
i = 0
in_prefix = true
foreach p : source_root
	if i >= build_root.length() or not in_prefix or build_root[i] != p
		in_prefix = false
		relative_dir_parts += p
	endif
	i += 1
endforeach
relative_dir = join_paths(relative_dir_parts) + '/'

# Strip relative path prefixes from the code if possible, otherwise hide them.
if cc.has_argument('-fmacro-prefix-map=/prefix/to/hide=')
	add_project_arguments(
		'-fmacro-prefix-map=@0@='.format(relative_dir),
		language: 'c',
	)
else
	add_project_arguments(
		'-DWLR_REL_SRC_DIR="@0@"'.format(relative_dir),
		language: 'c',
	)
endif

wlroots_proj = subproject(
  'wlroots',
  required: true,
  version: '0.15.1',
)
wlr_inc = wlroots_proj.get_variable('wlr_inc')

glew_proj = subproject(
  'glew',
  required: true,
  version: '2.2.0',
  default_options: [
    'egl=true',
    'default_library=static',
    'werror=false',
  ]
)
glew_dep = glew_proj.get_variable('glew_dep')

pixman_dep = dependency('pixman-1')
drm_dep = dependency('libdrm')

inc = include_directories('include')

sources = [
  'src/pixel_format.c',
  'src/renderer.c',
  'src/shaders.c',
  'src/texture.c'
]

dependencies = [
  drm_dep,
  glew_dep,
  pixman_dep,
]

lib_wlr_glew_renderer = static_library(
  meson.project_name(), sources,
  dependencies: dependencies,
  include_directories: [inc, wlr_inc],
  install: false,
)
