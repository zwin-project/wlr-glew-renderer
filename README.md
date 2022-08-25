## GLEW renderer for wlroots

[wlroots](https://gitlab.freedesktop.org/wlroots/wlroots) uses GLES2 for
OpenGL-based renderer. We want to use the newer OpenGL extenstion
functionalities, so we create a GLEW renderer with a similar API to the
existing GLES2 renderer.

## Building & Install

Build

```shell
meson build # this may take few minutes
ninja -C build # this may emit several warnings when compiling src_glew.c.o
```

Install like so

```
sudo meson install -C build --skip-subprojects
```

## Usage

```c
#include <wlr/renderer/glew.h>

struct wlr_renderer* renderer = wlr_glew_renderer_create_with_drm_fd(drm_fd);
```

## Notion

We build and use GLEW as a static library to ensure that we can use GLEW with
egl. (Patches that add an option to use GLEW as a dynamic library are also
welcome!)
Therefore, when using this renderer, do not link additional GLEW library.
