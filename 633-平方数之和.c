#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 633. 平方数之和
 * 
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
 * 
 * 示例1:
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例2:
 * 
 * 输入: 3
 * 输出: False
 */
/**
 * 思路：双指针，从[0,sqrt(c)]遍历
 */
bool judgeSquareSum(int c) {
    
    int a = 0, b = (int)sqrt(c);
    int result;
    while(a<=b) {
        result = a * a + b * b;
        if(result < c)
            a++;
        else if(result>c)
            b--;
        else
            return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    
    return 0;
}