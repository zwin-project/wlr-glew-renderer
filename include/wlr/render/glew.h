#ifndef WLR_RENDER_GLEW_H
#define WLR_RENDER_GLEW_H

#include <wlr/render/wlr_renderer.h>

struct wlr_egl;

struct wlr_renderer *wlr_glew_renderer_create_with_drm_fd(int drm_fd);
struct wlr_renderer *wlr_glew_renderer_create(struct wlr_egl *egl);

struct wlr_egl *wlr_glew_renderer_get_egl(struct wlr_renderer *renderer);

struct wlr_glew_texture_attribs {
  uint32_t target;
  uint32_t tex;

  bool has_alpha;
};

bool wlr_texture_is_glew(struct wlr_texture *texture);

void wlr_glew_texture_get_attribs(
    struct wlr_texture *texture, struct wlr_glew_texture_attribs *attribs);

#endif  //  WLR_RENDER_GLEW_H
