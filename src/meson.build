sources = [
  'pixel_format.c',
  'renderer.c',
  'shaders.c',
  'texture.c'
]

dependencies = [
  glew,
  wlroots,
]

lib_wlr_glew_renderer = library(
  meson.project_name(), sources,
  dependencies: dependencies,
  version: so_version,
  include_directories: inc,
  install: true,
)
