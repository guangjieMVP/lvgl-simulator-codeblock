#include "../lvgl/lvgl.h"
#include "stdio.h"


 lv_obj_t *label_obj;

void label_test(void)
{

    label_obj = lv_label_create(lv_scr_act(), NULL);
    lv_obj_set_pos(label_obj, 300, 200);
//    lv_label_set_style(label_obj, LV_LABEL_STYLE_MAIN, &lv_style_plain_color);
}

void lv_cpicker_test(void)
{
    lv_obj_t *cpicker;
    cpicker = lv_cpicker_create(lv_scr_act(), NULL);
    lv_obj_set_size(cpicker, 200, 200);
    lv_obj_align(cpicker, NULL, LV_ALIGN_CENTER, 0, 0);
}

lv_obj_t *bar;

void btn_event_cb(lv_obj_t * btn, lv_event_t event)
{
    static int16_t cnt = 0;

    char buf[10];
//    int16_t bar_min = lv_bar_get_min_value(bar);
 //   int16_t bar_max = lv_bar_get_min_value(bar);

    if(event == LV_EVENT_CLICKED) {
        sprintf(buf, "%d", cnt++);
        lv_label_set_text(label_obj, buf);
    }
}



void lv_bar_test(void)
{
    lv_style_t bar_bg_style;   //进度条背景样式
    lv_style_t bar_indic_style; //进度条的指示器样式


//    bar_bg_style.body.main_color = LV_COLOR_GREEN;
    lv_style_init(&bar_bg_style);
//    lv_style_set_radius(&bar_bg_style, LV_STATE_DEFAULT, 10);
//    lv_style_set_bg_opa(&bar_bg_style, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_bg_style, LV_STATE_DEFAULT, LV_COLOR_BLUE);

    bar = lv_bar_create(lv_scr_act(), NULL);

    lv_obj_add_style(bar, LV_BAR_PART_BG, &bar_bg_style);   //LV_BAR_PART_MAIN

    lv_bar_set_range(bar, 0, 100);

    lv_bar_set_anim_time(bar, 2000);

    lv_bar_set_range(bar, 0, 100);

    lv_bar_set_value(bar, 50, LV_ANIM_ON);

//    lv_obj_set_pos(bar, );


    lv_obj_align(bar, NULL, LV_ALIGN_IN_TOP_MID, 0, 100);
}



void lv_button_test_easy(void)
{
    static lv_style_t style_btn;

    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, LV_STATE_DEFAULT, 10);

    lv_style_set_transform_height(&style_btn, LV_STATE_PRESSED, -5);
    lv_style_set_transform_width(&style_btn, LV_STATE_PRESSED, -10);

    lv_obj_t *button;
    button = lv_btn_create(lv_scr_act(), NULL);

    lv_obj_add_style(button, LV_BTN_PART_MAIN, &style_btn);

    lv_obj_set_pos(button, 50, 50);
    lv_obj_t * label_button = lv_label_create(button, NULL);
    lv_label_set_text(label_button, "Button"); /*Set the labels text*/
    lv_obj_set_event_cb(button, btn_event_cb); /*Assign a callback to the*/
}

void lv_button_test_super(void)
{

/*    lv_obj_t *button;
    button = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_pos(button, 50, 50);
    lv_obj_set_size(button, 120, 50);
    lv_obj_set_event_cb(button, btn_event_cb);

    lv_obj_t *label =  lv_label_create(button, NULL);
    lv_label_set_text(label, "OK"); */

    static lv_style_t style_btn;
    static lv_style_t style_btn_red;
    /*Create a simple button style*/
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, LV_STATE_DEFAULT, 10);
    lv_style_set_bg_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_SILVER);
    lv_style_set_bg_grad_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_style_set_bg_grad_dir(&style_btn, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    /*Swap the colors in pressed state*/
    lv_style_set_bg_color(&style_btn, LV_STATE_PRESSED, LV_COLOR_GRAY);
    lv_style_set_bg_grad_color(&style_btn, LV_STATE_PRESSED, LV_COLOR_SILVER);
    /*Add a border*/
    lv_style_set_border_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_70);
    lv_style_set_border_width(&style_btn, LV_STATE_DEFAULT, 2);
    /*Different border color in focused state*/
    lv_style_set_border_color(&style_btn, LV_STATE_FOCUSED, LV_COLOR_BLUE);
    lv_style_set_border_color(&style_btn, LV_STATE_FOCUSED | LV_STATE_PRESSED, LV_COLOR_NAVY);


    /*Set the text style*/
    lv_style_set_text_color(&style_btn, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    /*Make the button smaller when pressed*/
    lv_style_set_transform_height(&style_btn, LV_STATE_PRESSED, -5);
    lv_style_set_transform_width(&style_btn, LV_STATE_PRESSED, -10);
    /*Add a transition to the size change*/
    static lv_anim_path_t path;
    lv_anim_path_init(&path);
    lv_anim_path_set_cb(&path, lv_anim_path_overshoot);
    lv_style_set_transition_prop_1(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_HEIGHT);
    lv_style_set_transition_prop_2(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_WIDTH);
    lv_style_set_transition_time(&style_btn, LV_STATE_DEFAULT, 300);
    lv_style_set_transition_path(&style_btn, LV_STATE_DEFAULT, &path);
    /*Create a red style. Change only some colors.*/
    lv_style_init(&style_btn_red);
    lv_style_set_bg_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_RED);
    lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_MAROON);
    lv_style_set_bg_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_MAROON);
    lv_style_set_bg_grad_color(&style_btn_red, LV_STATE_PRESSED, LV_COLOR_RED);
    lv_style_set_text_color(&style_btn_red, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    /*Create buttons and use the new styles*/
    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL); /*Add a button the␣
    , → current screen*/
    lv_obj_set_pos(btn, 10, 10); /*Set its position*/
    lv_obj_set_size(btn, 120, 50); /*Set its size*/
    lv_obj_reset_style_list(btn, LV_BTN_PART_MAIN); /*Remove the styles␣
    , → coming from the theme*/
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style_btn);
    lv_obj_t * label = lv_label_create(btn, NULL); /*Add a label to the␣
    , → button*/
    lv_label_set_text(label, "Button"); /*Set the labels text*/
    /*Create a new button*/
    lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), btn);
    lv_obj_set_pos(btn2, 10, 80);
    lv_obj_set_size(btn2, 120, 50); /*Set its size*/
    lv_obj_reset_style_list(btn2, LV_BTN_PART_MAIN); /*Remove the styles␣
    , → coming from the theme*/
    lv_obj_add_style(btn2, LV_BTN_PART_MAIN, &style_btn);
    lv_obj_add_style(btn2, LV_BTN_PART_MAIN, &style_btn_red); /*Add the red style␣
    , → on top of the current */
    lv_obj_set_style_local_radius(btn2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE); /*Add a local style*/
    label = lv_label_create(btn2, NULL); /*Add a label to the button*/
    lv_label_set_text(label, "Button 2"); /*Set the labels text*/
}

void my_demo_create(void)
{
    obj_test();
    label_test();
}

static lv_obj_t *slabel;

void slider_event_cb(lv_obj_t *slider, lv_event_t event)
{
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_label_set_text_fmt(slabel, "%d", lv_slider_get_value(slider));
    }
}


//滑动条测试的测试
void slider_demo_test(void)
{
    lv_obj_t *slider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_width(slider, 200);
    lv_obj_align(slider, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(slider, slider_event_cb);

    lv_slider_set_range(slider, 0, 500);
    lv_slider_set_anim_time(slider, 20);
    lv_slider_set_type(slider, false);

    lv_slider_get_left_value(slider);

    slabel = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(slabel, "0");
    lv_obj_set_auto_realign(slider, true);
    lv_obj_align(slabel, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
}

void obj_test(void)
{
    lv_obj_t * par = lv_obj_create(lv_scr_act(), NULL); /*Create a parent object on the current screen*/
    lv_obj_set_size(par, 100, 80);	                   /*Set the size of the parent*/

    lv_obj_t * obj1 = lv_obj_create(par, NULL);	         /*Create an object on the previously created parent object*/
    lv_obj_set_pos(obj1, 10, 10);

    lv_obj_set_pos(par, 200, 200);
}

void arc_test(void)
{
     lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);
     lv_arc_set_end_angle(arc, 200);

//       lv_arc_set_bg_angles(arc, 0, 360);

     lv_obj_set_pos(arc, 40, 200);
}

void lv_ex_bar_l(void)
{
     lv_style_t style;
     lv_style_init(&style);
//     lv_style_set_bg_opa(&style, LV_STATE_DEFAULT, LV_OPA_COVER);
//    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, LV_COLOR_SILVER);
    lv_style_set_bg_grad_color(&style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_bg_grad_dir(&style, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);

    lv_obj_t * bar1 = lv_bar_create(lv_scr_act(), NULL);
    lv_obj_set_size(bar1, 400, 30);
    lv_obj_align(bar1, NULL, LV_ALIGN_CENTER, 0, 0);

     lv_obj_set_pos(bar1, 200, 400);



    lv_obj_add_style(bar1, LV_OBJ_PART_MAIN, &style);


    lv_bar_set_range(bar1, 0, 1000);
    lv_bar_set_anim_time(bar1, 200);
    lv_bar_set_value(bar1, 0, LV_ANIM_ON);
}








