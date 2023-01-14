## GLEW renderer for wlroots

[wlroots](https://gitlab.freedesktop.org/wlroots/wlroots) uses GLES2 for
OpenGL-based renderer. We want to use the newer OpenGL extenstion
functionalities, so we create a GLEW renderer with a similar API to the
existing GLES2 renderer.

This repository is intended to be used only as a meson subproject
in this organization, and will not be installed as a library on the system.
