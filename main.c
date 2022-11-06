#include <stdio.h>
#include <stdlib.h>

#include "./model/mecanum.h"

mecanum_model_t model;
mecanum_source_t source;
mecanum_results_t results;

int main(){
    printf("----config model----\n");
    printf("x_len : ");
    scanf("%f",&model.x_len);
    printf("y_len : ");
    scanf("%f",&model.y_len);
    printf("wheel_r : ");
    scanf("%f",&model.wheel_r);

    while(1){
        printf("--------target input--------\n");
        printf("input x_speed:");
        scanf("%f",&results.x_speed);
        printf("input y_speed:");
        scanf("%f",&results.y_speed);
        printf("input cr_speed:");
        scanf("%f",&results.cr_speed);
        mecanum_inverse_calculate( &model , source , &results );
        printf("--------model--------\n");
        printf("x_len:%.1f\ny_len:%.1f\nwheel_r:%.1f\n",model.x_len,model.y_len,model.wheel_r);
        printf("--------target--------\n");
        printf("x_speed:%.1f y_speed:%.1f cr_speed:%.1f\n",results.x_speed,results.y_speed,results.cr_speed);
        printf("--------motor speed--------\n");
        printf("m1\tm2\tm3\tm4\n");
        for(int temp = 0;temp<4;temp++){
            printf("%.3f\t",source[temp]);
        }
        printf("\n");
    }

    system("pause");

    return 0;
}

