// 验证二叉查找树.cpp : 定义控制台应用程序的入口点。
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

TreeNode *tn;                 //应该写成类内成员变量，表示前一个结点

//递归中序遍历二叉查找树
bool isValidBST(TreeNode * root) {
	// write your code here
	if (!root)
		return true;	
	bool lis, ris = true;
	lis=isValidBST(root->left);

	if (!tn)
		tn = root;
	else
	{
		if (root->val > tn->val)           //如果该节点值比前一个访问的结点值大
			tn = root;
		else
			return false;                 //否则直接返回false;
	}
	ris=isValidBST(root->right);
	if (lis&&ris)
		return true;
	else
		return false;
}

int main()
{
	TreeNode tn1 = TreeNode(1);
	TreeNode tn2 = TreeNode(1);
	tn1.left = &tn2;
	
	isValidBST(&tn1);
    return 0;
}

