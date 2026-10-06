#include <lvgl.h>
#include "rabbit_image.c"

/* GEM's peripheral screen calls this hook; render one fixed frame. */
void draw_animation(lv_obj_t *parent) {
    lv_obj_t *art = lv_img_create(parent);
    lv_img_set_src(art, &rabbit_image);
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 36, 0);
}
