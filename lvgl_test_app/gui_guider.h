/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_list1;
	lv_obj_t *screen_spinbox3;
	lv_obj_t *screen_spinbox3_btn;
	lv_obj_t *screen_spinbox3_btn_minus;
	lv_obj_t *screen_sw4;
	lv_obj_t *screen_gauge3;
}lv_ui;

extern lv_ui guider_ui;

void setup_ui(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);


#ifdef __cplusplus
}
#endif
#endif
