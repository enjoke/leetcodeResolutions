#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void getLeaves(struct TreeNode *root, int *array, int *index)
{
	if(NULL == root)
		return;
	if(NULL == root->left && NULL == root->right){
		array[(*index)++] = root->val;             
		return;
	}
	getLeaves(root->left, array, index);
	getLeaves(root->right, array, index);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
	if(NULL == root1 && NULL == root2)
		return true;
	if(NULL == root1 || NULL == root2)
		return false;

	int leaves1[101], leaves2[101];
	int idx1 = 0, idx2 = 0;
	getLeaves(root1, leaves1, &idx1);
	getLeaves(root2, leaves2, &idx2);

	if(idx1 != idx2)
		return false;
	for(int i=0; i<idx1; i++)
		if(leaves1[i] != leaves2[i])
			return false;
	return true;
}
