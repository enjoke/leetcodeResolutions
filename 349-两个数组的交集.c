#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 349. 两个数组的交集
 * 
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 说明:
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int hash[4294967296] = { 0 };
    int cnt = 0;
    int *array = (int*)malloc(sizeof(int) *(nums2Size <nums1Size ? nums2Size : nums1Size));
    for(int i=0; i<nums1Size; i++)
            hash[nums1[i] + 2147483648]++;
    
    for(int i=0; i<nums2Size; i++){
        if(hash[nums2[i] + 2147483648] > 0){
            hash[nums2[i] + 2147483648]--;
            array[cnt++] = nums2[i];
        }
    }
    *returnSize = cnt;
    return array;
}
int main(int argc, char **argv)
{
    
    return 0;
}