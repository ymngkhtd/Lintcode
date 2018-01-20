// 二叉查找树插入节点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;

	}

};

TreeNode* Insert(TreeNode *root, TreeNode *node);

TreeNode * insertNode(TreeNode * root, TreeNode * node) {
	// write your code here
	if (!node)
		return NULL;
	if (!root)
	{
		root = node;
		return root;
	}

	return	Insert(root, node);

}

TreeNode* Insert(TreeNode *root, TreeNode *node)
{
	if (!root)
		return NULL;
		TreeNode *a,*b= NULL;
		if (root->val > node->val)
		{
			a = Insert(root->left, node);
			if (a == NULL)
			{
				root->left = node;
			}
		}	
	else
	{
		b=Insert(root->right, node);
		if (b == NULL)
		{
			root->right = node;
		}
	}


	return root;
}

int main()
{
	TreeNode *a=NULL;
	TreeNode b = TreeNode(3);
	insertNode(a, &b);
    return 0;
}

