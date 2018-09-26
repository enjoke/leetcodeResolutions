#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 868. 二进制间距
 * 
 * 给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 
 * 如果没有两个连续的 1，返回 0 。
 * 示例 3：
 * 输入：6
 * 输出：1
 * 解释：
 * 6 的二进制是 0b110 。
 * 提示：
 * 1 <= N <= 10^9
 */

/**
 * 思路：
 * 取出N的每个为1的位置索引，比较其与前一个为1位置的距离，算出最大值
 */
int binaryGap(int N) {
    int last = -1, ans = 0;
    for(int i = 0; i < 32; i++) {
        if(((N>>i) & 1) != 0) {
            if(last >= 0) {
                ans = ans > (i - last) ? ans : i - last;
            }
            last = i;
        }
    }
    return ans;
}