#include<iostream>
#include<algorithm>
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



class Solution {
public:
	/*
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return 0;
		int mps = INT_MIN;
		Getmps(root, mps);
		return mps;
	}

	int Getmps(TreeNode *tn, int &res)
	{
		if (tn == NULL)
			return 0;
		int leftmps = max(0, Getmps(tn->left, res));       //当前节点值加左树的最大路径
		int rightmps = max(0, Getmps(tn->right, res));     //当前节点值加右树的最大路径

		res = max(res,max(0,leftmps)+max(0,rightmps)+tn->val);   //若以当前节点为顶点的最大路径较大，则更新最大路径

		return max(0, max(leftmps, rightmps) + tn->val);     //返回左子树最大路径与右子树最大路径较大的一方加当前节点值
	}
};

int main()
{

}
