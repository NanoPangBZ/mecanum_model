/*
 * @Author: 没人要的野指针 https://github.com/CodingBugStd
 * @Date: 2022-11-05 08:10:43
 * @LastEditors: 没人要的野指针 https://github.com/CodingBugStd
 * @LastEditTime: 2022-11-08 01:05:26
 * @Description: 矩形麦克纳姆轮运动学正逆解
 * Copyright (c) 2022 CodingBugStd, All Rights Reserved. 
 */
#ifndef _MECANUM_H_
#define _MECANUM_H_

/**
 *
 * 脉轮定义      坐标轴定义             电机旋转正方向:左手定则
 * M1----M2     x:👆                   M1:->   M2:->
 * |     |      y:👉                   M3:->   M4:->
 * M3----M4     z:垂直水平面向上
 *              相对几何中心为原点
*/

//参考资料 : https://mp.weixin.qq.com/s/GWhlXsuY6QYyoZydaSYpjQ

//使用时 模型单位应当统一!!
//长度 角度 转速 速度
// mm rad  rad/s mm/s
// cm rad  rad/s cm/s
// mm n    n/min mm/min



/********************************具体类型定义**********************/
//麦克纳姆轮小车四个电机的速度(标量)
typedef float mecanum_motor_speed_t[4];

//麦克纳姆轮小车几何中心的速度(矢量)
typedef struct{
    float x_speed;
    float y_speed;
    float cr_speed;    //center_rotation_speed 几何中心旋转速度
}mecanum_center_speed_t;

/******************************模型类型定义**********************/
//运动学模型的输入 -> 4个轮子的转速
typedef mecanum_motor_speed_t mecanum_input_t;

//运动学模型的输出 -> 几何中心的速度
typedef mecanum_center_speed_t mecanum_output_t;

//运动学模型的常量
typedef struct{
    float x_len;    //几何中心到轮子的长度在x方向上的投影长度
    float y_len;    //几何中心到轮子的长度在y方向上的投影长度
    float wheel_r;  //轮子半径
}mecanum_constant_t;



/*****************************基本正逆解函数***************************/

/**
 * @brief 麦克纳姆轮运动学正解，通过输入解出输出
 * @param model 麦克纳姆轮模型
 * @param input 输入
 * @param output 输出
 */
void mecanum_positive_calculate(const mecanum_constant_t* model,mecanum_input_t* input,mecanum_output_t* output);

/**
 * @brief 麦克纳姆轮运动学逆解，通过输出反解输入
 * @param model 麦克纳姆轮模型
 * @param input 输入
 * @param output 输出
 */
void mecanum_inverse_calculate(const mecanum_constant_t* model,mecanum_input_t* input,mecanum_output_t* output);

/***********************开环积分函数*********************************/

#endif  //_MECANUM_H_

