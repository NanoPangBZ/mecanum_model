/*
 * @Author: 没人要的野指针
 * @Date: 2022-11-05 08:10:43
 * @LastEditors: 没人要的野指针
 * @LastEditTime: 2022-11-06 23:02:23
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

//源 -> 4个轮子的转速(标量)
typedef float mecanum_source_t[4];

//结果 -> 几何中心的速度(矢量)
typedef struct{
    float x_speed;
    float y_speed;
    float cr_speed;    //center_rotation_speed 几何中心旋转速度
}mecanum_results_t;

//模型
typedef struct{
    float x_len;    //几何中心到轮子的长度在x方向上的投影长度
    float y_len;    //几何中心到轮子的长度在y方向上的投影长度
    float wheel_r;  //轮子半径
}mecanum_model_t;

//运动学正解
void mecanum_positive_calculate(const mecanum_model_t*,mecanum_source_t,mecanum_results_t*);
//运动学逆解
void mecanum_inverse_calculate(const mecanum_model_t*,mecanum_source_t,mecanum_results_t*);

#endif  //_MECANUM_H_

