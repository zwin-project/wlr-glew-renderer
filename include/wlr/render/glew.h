#ifndef WLR_RENDER_GLEW_H
#define WLR_RENDER_GLEW_H

#include <wlr/render/wlr_renderer.h>

struct wlr_egl;

struct wlr_renderer *wlr_glew_renderer_create_with_drm_fd(int drm_fd);
struct wlr_renderer *wlr_glew_renderer_create(struct wlr_egl *egl);

struct wlr_egl *wlr_glew_renderer_get_egl(struct wlr_renderer *renderer);

#endif  //  WLR_RENDER_GLEW_H
