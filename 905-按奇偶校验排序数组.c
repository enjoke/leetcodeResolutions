#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {  
    int *array = (int*)malloc(sizeof(int) * ASize);
    int left = 0, right = ASize - 1;
    for(int i=0; i<ASize; i++){
        if(A[i] % 2 == 0)
            array[left++] = A[i];
        else
            array[right--] = A[i];
    }
    *returnSize = ASize;

    return array;
}
int main(int argc, char **argv)
{
    
    return 0;
}