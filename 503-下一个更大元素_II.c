#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    
    int *array = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int index = 0, j;
    for(int i=0; i<numsSize; i++){

        for(j=i+1;j<numsSize;j++){
            if(nums[i] < nums[j]){
                array[index++] = nums[j];
                break;
            }
        }
        if(j == numsSize){
            for(j=0; j<i; j++){
               if(nums[i] < nums[j]){
                array[index++] = nums[j];
                break;
                }
            }
            if(j == i){
               array[index++] = -1; 
            }
        }
    }

    return array;
}
int main(int argc, char **argv)
{
    
    return 0;
}