#include <stdio.h>
 int main(void){
    int nums[]= {3, 8, 9, 11, 16, 18, 19, 21};
    int len = sizeof(nums)/sizeof(nums[0]);
    int target = 25;
    int left =0;
    int right = len -1 ;
    while ( right > left ){
        if ( nums[left] + nums [right] == target ){
            printf( "%d %d\n", left, right);
            return 0;

        } else if ( nums[left] + nums [right] > target ){
            right --;
        }else{
            left ++;
        }
    }
    printf ( "нету такого числа\n");
    return 0;
 }