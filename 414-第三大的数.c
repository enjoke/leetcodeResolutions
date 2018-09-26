#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 
 * 414. 第三大的数
 * 
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 示例 2:
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 示例 3:
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 */
/**
 * 思路
 * 1.排序
 * 2.对已排序数组从右到左即从大到小遍历，并统计不同元素个数
 * 3.如果元素数目>=3则返回第三大，否则返回最大
 */
int comp(int* a, int *b){
    if(*(int*) a == INT_MIN)
        return -1;
    if(*(int*) b == INT_MIN)
        return 1;
    return *(int*)a - *(int*)b;
}

int thirdMax(int* nums, int numsSize) {
    
    
    qsort(nums, numsSize, sizeof(int), comp);
    
    int cnt = 1, max, sec, third;
    
    third = max = nums[numsSize - 1];
    for(int i=numsSize - 2; i>=0 && cnt < 3; i--){
        if(nums[i] < third){
            third = nums[i];
            cnt++;
        }
    }
    
    return cnt < 3 ? max : third;
}
int main(int argc, char **argv)
{
    
    return 0;
}