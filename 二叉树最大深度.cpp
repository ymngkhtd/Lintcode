#include<iostream>

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



int maxDepth(TreeNode *root) {
	// write your code here

	int i = 1;
	if (root == NULL)
		return 0;

	int r = maxDepth(root->right);

	int l = maxDepth(root->left);

	return i+ (r > l ? r : l);
}

int main()
{
	TreeNode *tn = &TreeNode(2);

	int m=maxDepth(tn);
}