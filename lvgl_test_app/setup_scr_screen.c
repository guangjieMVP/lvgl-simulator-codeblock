/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */


#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"

lv_coord_t h;
lv_ui guider_ui;

static lv_obj_t * screen_spinbox3;
static void lv_screen_spinbox3_increment_event_cb(lv_obj_t * screen_spinbox3_btn, lv_event_t event)
{
	if(event == LV_EVENT_SHORT_CLICKED || event == LV_EVENT_LONG_PRESSED_REPEAT){
	lv_spinbox_increment(screen_spinbox3);
	}
}
static void lv_screen_spinbox3_decrement_event_cb(lv_obj_t * screen_spinbox3_btn, lv_event_t event)
{
	if(event == LV_EVENT_SHORT_CLICKED || event == LV_EVENT_LONG_PRESSED_REPEAT){
	lv_spinbox_decrement(screen_spinbox3);
	}
}

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_list1
	ui->screen_list1 = lv_list_create(ui->screen, NULL);
	lv_list_set_edge_flash(ui->screen_list1, true);
	lv_list_set_anim_time(ui->screen_list1, 255);

	//Write style LV_LIST_PART_BG for screen_list1
	static lv_style_t style_screen_list1_bg;
	lv_style_init(&style_screen_list1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_list1_bg
	lv_style_set_radius(&style_screen_list1_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_screen_list1_bg, LV_STATE_DEFAULT, lv_color_make(0x28, 0x42, 0x6c));
	lv_style_set_border_width(&style_screen_list1_bg, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->screen_list1, LV_LIST_PART_BG, &style_screen_list1_bg);

	//Write style LV_LIST_PART_SCROLLABLE for screen_list1
	static lv_style_t style_screen_list1_scrollable;
	lv_style_init(&style_screen_list1_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_screen_list1_scrollable
	lv_style_set_radius(&style_screen_list1_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_list1_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_list1_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_list1_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_list1_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_list1, LV_LIST_PART_SCROLLABLE, &style_screen_list1_scrollable);

	//Write style LV_BTN_PART_MAIN for screen_list1
	static lv_style_t style_screen_list1_main_child;
	lv_style_init(&style_screen_list1_main_child);

	//Write style state: LV_STATE_DEFAULT for style_screen_list1_main_child
	lv_style_set_radius(&style_screen_list1_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_list1_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_list1_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_list1_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_list1_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_list1_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->screen_list1, 428, 34);
	lv_obj_set_size(ui->screen_list1, 159, 117);
	lv_obj_t *screen_list1_btn;
	screen_list1_btn = lv_list_add_btn(ui->screen_list1, LV_SYMBOL_SAVE, "save");
	lv_obj_add_style(screen_list1_btn, LV_BTN_PART_MAIN, &style_screen_list1_main_child);
	screen_list1_btn = lv_list_add_btn(ui->screen_list1, LV_SYMBOL_AUDIO, "music");
	lv_obj_add_style(screen_list1_btn, LV_BTN_PART_MAIN, &style_screen_list1_main_child);
	screen_list1_btn = lv_list_add_btn(ui->screen_list1, LV_SYMBOL_VIDEO, "video");
	lv_obj_add_style(screen_list1_btn, LV_BTN_PART_MAIN, &style_screen_list1_main_child);

	//Write codes screen_spinbox3
	ui->screen_spinbox3 = lv_spinbox_create(ui->screen, NULL);

	//Write style LV_SPINBOX_PART_BG for screen_spinbox3
	static lv_style_t style_screen_spinbox3_bg;
	lv_style_init(&style_screen_spinbox3_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_spinbox3_bg
	lv_style_set_radius(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_pad_bottom(&style_screen_spinbox3_bg, LV_STATE_DEFAULT, 10);
	lv_obj_add_style(ui->screen_spinbox3, LV_SPINBOX_PART_BG, &style_screen_spinbox3_bg);

	//Write style LV_SPINBOX_PART_CURSOR for screen_spinbox3
	static lv_style_t style_screen_spinbox3_cursor;
	lv_style_init(&style_screen_spinbox3_cursor);

	//Write style state: LV_STATE_DEFAULT for style_screen_spinbox3_cursor
	lv_style_set_bg_color(&style_screen_spinbox3_cursor, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_spinbox3_cursor, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_spinbox3_cursor, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_spinbox3_cursor, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_spinbox3, LV_SPINBOX_PART_CURSOR, &style_screen_spinbox3_cursor);

	//Write style LV_BTN_PART_MAIN for screen_spinbox3
	static lv_style_t style_screen_spinbox3_main_child;
	lv_style_init(&style_screen_spinbox3_main_child);

	//Write style state: LV_STATE_DEFAULT for style_screen_spinbox3_main_child
	lv_style_set_radius(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_spinbox3_main_child, LV_STATE_DEFAULT, 2);
	lv_obj_set_pos(ui->screen_spinbox3, 451, 208);
	screen_spinbox3 = ui->screen_spinbox3;
	lv_obj_set_width(ui->screen_spinbox3, 87);
	lv_spinbox_set_digit_format(ui->screen_spinbox3, 5, 3);
	lv_spinbox_step_prev(ui->screen_spinbox3);
	lv_spinbox_set_range(ui->screen_spinbox3, -99999, 99999);
	h = lv_obj_get_height(ui->screen_spinbox3);
	ui->screen_spinbox3_btn = lv_btn_create(ui->screen, NULL);
	lv_obj_set_size(ui->screen_spinbox3_btn, h, h);
	lv_obj_align(ui->screen_spinbox3_btn, ui->screen_spinbox3, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
	lv_theme_apply(ui->screen_spinbox3_btn, LV_THEME_SPINBOX_BTN);
	lv_obj_set_style_local_value_str(ui->screen_spinbox3_btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_SYMBOL_PLUS);
	lv_obj_set_event_cb(ui->screen_spinbox3_btn, lv_screen_spinbox3_increment_event_cb);
	ui->screen_spinbox3_btn_minus = lv_btn_create(ui->screen, ui->screen_spinbox3_btn);
	lv_obj_align(ui->screen_spinbox3_btn_minus,ui->screen_spinbox3, LV_ALIGN_OUT_LEFT_MID, -5, 0);
	lv_obj_set_event_cb(ui->screen_spinbox3_btn_minus, lv_screen_spinbox3_decrement_event_cb);
	lv_obj_set_style_local_value_str(ui->screen_spinbox3_btn_minus, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_SYMBOL_MINUS);
	lv_obj_add_style(ui->screen_spinbox3_btn, LV_BTN_PART_MAIN, &style_screen_spinbox3_main_child);
	lv_obj_add_style(ui->screen_spinbox3_btn_minus, LV_BTN_PART_MAIN, &style_screen_spinbox3_main_child);

	//Write codes screen_sw4
	ui->screen_sw4 = lv_switch_create(ui->screen, NULL);

	//Write style LV_SWITCH_PART_BG for screen_sw4
	static lv_style_t style_screen_sw4_bg;
	lv_style_init(&style_screen_sw4_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw4_bg
	lv_style_set_radius(&style_screen_sw4_bg, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw4_bg, LV_STATE_DEFAULT, lv_color_make(0x31, 0x80, 0xb4));
	lv_style_set_bg_grad_color(&style_screen_sw4_bg, LV_STATE_DEFAULT, lv_color_make(0x29, 0x63, 0x89));
	lv_style_set_bg_grad_dir(&style_screen_sw4_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw4_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw4, LV_SWITCH_PART_BG, &style_screen_sw4_bg);

	//Write style LV_SWITCH_PART_INDIC for screen_sw4
	static lv_style_t style_screen_sw4_indic;
	lv_style_init(&style_screen_sw4_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw4_indic
	lv_style_set_radius(&style_screen_sw4_indic, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw4_indic, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_sw4_indic, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_screen_sw4_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw4_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw4, LV_SWITCH_PART_INDIC, &style_screen_sw4_indic);

	//Write style LV_SWITCH_PART_KNOB for screen_sw4
	static lv_style_t style_screen_sw4_knob;
	lv_style_init(&style_screen_sw4_knob);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw4_knob
	lv_style_set_radius(&style_screen_sw4_knob, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_sw4_knob, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_sw4_knob, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw4_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw4_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_sw4, LV_SWITCH_PART_KNOB, &style_screen_sw4_knob);
	lv_obj_set_pos(ui->screen_sw4, 103, 73);
	lv_obj_set_size(ui->screen_sw4, 146, 20);
	lv_switch_set_anim_time(ui->screen_sw4, 200);

	//Write codes screen_gauge3
	ui->screen_gauge3 = lv_gauge_create(ui->screen, NULL);

	//Write style LV_GAUGE_PART_MAIN for screen_gauge3
	static lv_style_t style_screen_gauge3_main;
	lv_style_init(&style_screen_gauge3_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge3_main
	lv_style_set_bg_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_gauge3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_gauge3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0x39, 0x3c, 0x41));
	lv_style_set_text_font(&style_screen_gauge3_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_gauge3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_inner(&style_screen_gauge3_main, LV_STATE_DEFAULT, 15);
	lv_style_set_line_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_line_width(&style_screen_gauge3_main, LV_STATE_DEFAULT, 3);
	lv_style_set_line_opa(&style_screen_gauge3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_end_color(&style_screen_gauge3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_width(&style_screen_gauge3_main, LV_STATE_DEFAULT, 9);
	lv_style_set_scale_border_width(&style_screen_gauge3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_scale_end_border_width(&style_screen_gauge3_main, LV_STATE_DEFAULT, 5);
	lv_style_set_scale_end_line_width(&style_screen_gauge3_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->screen_gauge3, LV_GAUGE_PART_MAIN, &style_screen_gauge3_main);

	//Write style LV_GAUGE_PART_MAJOR for screen_gauge3
	static lv_style_t style_screen_gauge3_major;
	lv_style_init(&style_screen_gauge3_major);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge3_major
	lv_style_set_line_color(&style_screen_gauge3_major, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_line_width(&style_screen_gauge3_major, LV_STATE_DEFAULT, 5);
	lv_style_set_line_opa(&style_screen_gauge3_major, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_screen_gauge3_major, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_end_color(&style_screen_gauge3_major, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_width(&style_screen_gauge3_major, LV_STATE_DEFAULT, 16);
	lv_style_set_scale_end_line_width(&style_screen_gauge3_major, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen_gauge3, LV_GAUGE_PART_MAJOR, &style_screen_gauge3_major);

	//Write style LV_GAUGE_PART_NEEDLE for screen_gauge3
	static lv_style_t style_screen_gauge3_needle;
	lv_style_init(&style_screen_gauge3_needle);

	//Write style state: LV_STATE_DEFAULT for style_screen_gauge3_needle
	lv_style_set_size(&style_screen_gauge3_needle, LV_STATE_DEFAULT, 21);
	lv_style_set_bg_color(&style_screen_gauge3_needle, LV_STATE_DEFAULT, lv_color_make(0x41, 0x48, 0x5a));
	lv_style_set_bg_grad_color(&style_screen_gauge3_needle, LV_STATE_DEFAULT, lv_color_make(0x41, 0x48, 0x5a));
	lv_style_set_bg_grad_dir(&style_screen_gauge3_needle, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_gauge3_needle, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_inner(&style_screen_gauge3_needle, LV_STATE_DEFAULT, 0);
	lv_style_set_line_width(&style_screen_gauge3_needle, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_screen_gauge3_needle, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_gauge3, LV_GAUGE_PART_NEEDLE, &style_screen_gauge3_needle);
	lv_obj_set_pos(ui->screen_gauge3, 125, 172);
	lv_obj_set_size(ui->screen_gauge3, 200, 200);
	lv_gauge_set_scale(ui->screen_gauge3, 300, 37, 19);
	lv_gauge_set_range(ui->screen_gauge3, 0, 180);
	static lv_color_t needle_colors_screen_gauge3[1];
	needle_colors_screen_gauge3[0] = lv_color_make(0xff, 0x00, 0x00);
	lv_gauge_set_needle_count(ui->screen_gauge3, 1, needle_colors_screen_gauge3);
	lv_gauge_set_critical_value(ui->screen_gauge3, 120);
	lv_gauge_set_value(ui->screen_gauge3, 0, 0);
}
