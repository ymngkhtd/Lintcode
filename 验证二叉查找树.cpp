// ��֤���������.cpp : �������̨Ӧ�ó������ڵ㡣
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

TreeNode *tn;                 //Ӧ��д�����ڳ�Ա��������ʾǰһ�����

//�ݹ�����������������
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
		if (root->val > tn->val)           //����ýڵ�ֵ��ǰһ�����ʵĽ��ֵ��
			tn = root;
		else
			return false;                 //����ֱ�ӷ���false;
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

