#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void func(int *a, int b, int *index){
    if(*index == 0){
        if(a[(*index)] * b < 0){
            if(a[(*index)] < -b)
                a[(*index)++] =b;
            else if(a[(*index)] > -b)
                (*index)++;
        } else {
            a[(*index)+1] = b;
            (*index) += 2;
        }
        return;
    }
    if(a[(*index)-1] * b < 0){
            if(a[(*index)-1] < -b){
                (*index)--;
                return func(a, b, index);
            } else if(a[(*index)-1] == -b){
                (*index)--; //互为相反数，直接炸飞上一个
                return;
            }
    } else {
        a[(*index)++] = b;
        return;
    }

}
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    
    int *array = (int*)malloc(sizeof(int) * asteroidsSize);
    int star = asteroids[asteroidsSize - 1];
    int index = 1;
    array[0] = asteroids[0];
    for(int i = 1; i<asteroidsSize; i++){
        func(array, asteroids[i], &index);
    }

    *returnSize = index;
    return array;
}