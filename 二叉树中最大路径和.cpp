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
		int leftmps = max(0, Getmps(tn->left, res));       //��ǰ�ڵ�ֵ�����������·��
		int rightmps = max(0, Getmps(tn->right, res));     //��ǰ�ڵ�ֵ�����������·��

		res = max(res,max(0,leftmps)+max(0,rightmps)+tn->val);   //���Ե�ǰ�ڵ�Ϊ��������·���ϴ���������·��

		return max(0, max(leftmps, rightmps) + tn->val);     //�������������·�������������·���ϴ��һ���ӵ�ǰ�ڵ�ֵ
	}
};

int main()
{

}
