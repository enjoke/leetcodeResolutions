#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * 思路：p,q在不同子树(一左一右),则返回root
 * 否则，返回在左/右子树先找到的节点。
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==NULL||root->val==p->val||root->val==q->val)
        return root;
    struct TreeNode* left=lowestCommonAncestor(root->left,p,q);
    struct TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left&&right)
        return root;
    else if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else
        return NULL;
}

// 我的解答
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 void findAncesto(struct TreeNode* root, int val, struct TreeNode** a, int *index, int *flag){
     if(NULL == root)
        return;
    
    if(val == root->val){
        a[(*index)++] = root;
        *flag = 1;
        return;
    }
    if(!*flag)
        findAncesto(root->left, val, a, index, flag);
    if(!*flag)
        findAncesto(root->right, val, a, index, flag);
    if(*flag)
        a[(*index)++] = root;
 }

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* a[1001] = {NULL}, *b[1001] = {NULL};
    int ai = 0, bi=0, flag = 0;
    findAncesto(root, p->val, &a, &ai, &flag);
    flag = 0;
    findAncesto(root, q->val, &b, &bi, &flag);
    ai--;
    bi--;
    while(ai >= 0&& bi >= 0){
        if(a[ai] != b[bi])
            break;

    }

    return a[ai+1];
}
int main(int argc, char **argv)
{
    
    return 0;
}