/*
 * @Author: 没人要的野指针
 * @Date: 2022-11-05 08:10:43
 * @LastEditors: 没人要的野指针
 * @LastEditTime: 2022-11-06 23:05:53
 * @Description: 矩形麦克纳姆轮运动学正逆解
 * Copyright (c) 2022 CodingBugStd, All Rights Reserved. 
 */
#include "mecanum.h"

//运动学正解
void mecanum_positive_calculate(const mecanum_model_t* model,mecanum_source_t source,mecanum_results_t* results){
    
}

//运动学逆解
void mecanum_inverse_calculate(const mecanum_model_t* model,mecanum_source_t source,mecanum_results_t* results){
    float vz = (results->x_speed + results->y_speed) / model->wheel_r;
    float vf = (results->x_speed - results->y_speed) / model->wheel_r;
    float w;
    if( results->cr_speed != 0 ){
        w = (model->x_len + model->y_len) / results->cr_speed;
    }else{
        w = 0;
    }
    source[0] = vf - w ;
    source[1] = vz - w ;
    source[2] = vf + w ;
    source[3] = vz + w ;
}



