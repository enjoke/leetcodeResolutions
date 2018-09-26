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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void func(struct TreeNode* root, int *val, int *min){
    if(NULL == root)
        return;
    
    func(root->left, val, min);
    if(val != 0)
        *min = root->val - *val < *min ? root->val - *val : *min;
    *val = root->val;
    func(root->right, val, min);
}
int minDiffInBST(struct TreeNode* root) {
    int val = 0, min = 65535;
    func(root, &val, &min);
    return min;
}
int main(int argc, char **argv)
{
    
    return 0;
}