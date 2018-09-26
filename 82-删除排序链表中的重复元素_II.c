#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 82. 删除排序链表中的重复元素 II
 * 
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 */

typedef struct ListNode {
    int val;
    struct ListNode *next;
} node;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **p = &head; 
    struct ListNode **q = NULL;
    int num = -1;
    while(*p){
        if((*p)->val == num){
            if(q != NULL){
                *q = (*p)->next;
                *p = *q;
                q = NULL;
            } else {
                *p = (*p)->next;
            }
        }
        else{
            num = (*p)->val;
            q = p;
            p = &((*p)->next);
        }
    }
    return head;
}
int main(int argc, char **argv)
{
    node node5 = {5,NULL};
    node node4_2 = {4, &node5};
    node node4_1 = {4, &node4_2};
    node node3_2 = {3, &node4_1};
    node node3_1 = {3, &node3_2};
    node node2 = {2, &node3_1};
    node node1 = {1, &node2};
    node *p = deleteDuplicates(&node1);
    while(p){
        printf("%d", p->val);
        p = p->next;
        if(p)
        printf("->");
    }
    system("PAUSE");
    return 0;
}