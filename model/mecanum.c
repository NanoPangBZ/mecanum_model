/*
 * @Author: 没人要的野指针 https://github.com/CodingBugStd
 * @Date: 2022-11-05 08:10:43
 * @LastEditors: 没人要的野指针 https://github.com/CodingBugStd
 * @LastEditTime: 2022-11-08 00:57:38
 * @Description: 矩形麦克纳姆轮运动学正逆解
 * Copyright (c) 2022 CodingBugStd, All Rights Reserved. 
 */
#include "mecanum.h"

//运动学正解
void mecanum_positive_calculate(const mecanum_constant_t* model,mecanum_input_t* source,mecanum_output_t* results){
    float v23 = (*source)[1] + (*source)[2];
    float v14 = (*source)[0] + (*source)[3];
    float rxy = 1.0f / (model->x_len + model->y_len);
    float r4 = model->wheel_r / 4.0f;
    results->x_speed = (v23 + v14) * r4;
    results->y_speed = (v14 - v23 ) * r4;
    results->cr_speed = ( (*source)[0] + (*source)[2] - (*source)[1] - (*source)[3] ) * rxy * r4;
}

//运动学逆解
void mecanum_inverse_calculate(const mecanum_constant_t* model,mecanum_input_t* source,mecanum_output_t* results){
    float vz = (results->x_speed + results->y_speed) / model->wheel_r;
    float vf = (results->x_speed - results->y_speed) / model->wheel_r;
    float w;
    if( results->cr_speed != 0 ){
        w = (model->x_len + model->y_len) * results->cr_speed / model->wheel_r;
    }else{
        w = 0;
    }
    (*source)[0] = vz + w ;
    (*source)[1] = vf - w ;
    (*source)[2] = vf + w ;
    (*source)[3] = vz - w ;
}

