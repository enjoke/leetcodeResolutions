#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 501. 二叉搜索树中的众数
 * 题目要求：
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 假定 BST 有如下定义：
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 例如：
 * 给定 BST [1,null,2,2],
 * 1
 *  \
 *   2
 *  /
 * 2
 * 返回[2].
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * 思路:
 * 利用二叉搜索树的特点，按照以中序顺序，按照左->根->右顺序遍历二叉搜索树，即以从小到大的顺序遍历二叉搜索树
 * 边遍历边计数
 */
void func(struct TreeNode *root, struct TreeNode **preNode, 
	int *max, int *cnt, int *array, int *index) {
		if(NULL == root)
			return;

		func(root->left, preNode, max, cnt, array, index);
		if(NULL != *preNode){ //存在参考节点，比较统计
			*cnt = (root->val == (*preNode)->val) ? *cnt + 1: 1;
		}
		if(*cnt >= *max){   //新众数
			if(*cnt > *max){ //重置数组
				*max = *cnt;
				*index = 0;
			}
			array[(*index)++] = root->val;
		}

		*preNode = root; //统计完该节点，以该节点做为参考节点

		func(root->right, preNode, max, cnt, array, index);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize) {
    int max = -1, cnt = 1, index = 0;
	int *array = (int*)malloc(sizeof(int) * 8192);
	struct TreeNode *p=NULL;
	func(root, &p, &max, &cnt, array, &index);
	*returnSize = index;
	return array;
}