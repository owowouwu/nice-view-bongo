/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include "widgets/status.h"
#include "widgets/modifiers.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
static struct zmk_widget_status status_widget;
#endif

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
static struct zmk_widget_modifiers modifiers_widget;
#endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
    zmk_widget_status_init(&status_widget, screen);
    // Position status widget on the left side
    lv_obj_align(zmk_widget_status_obj(&status_widget), LV_ALIGN_LEFT_MID, 0, 0);
#endif

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zmk_widget_modifiers_init(&modifiers_widget, screen);
    // Position modifiers widget to the right of the status widget
    lv_obj_align_to(zmk_widget_modifiers_obj(&modifiers_widget), 
                    zmk_widget_status_obj(&status_widget),
                    LV_ALIGN_OUT_RIGHT_MID, 10, 0);  // 10px gap between widgets
#endif

    return screen;
}
