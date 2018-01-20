#include<iostream>
#include<stack>
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


//递归的方法
//void fzecs(TreeNode *root) {
//	// write your code here
//
//	if (root == NULL)
//		return ;
//	fzecs(root->right);
//	fzecs(root->left);
//	TreeNode *n = root->right;
//	root->right = root->left;
//	root->left = n;
//
//}

//非递归的方法
void invertBinaryTree(TreeNode * root) {
	// write your code here
	if (root == NULL)
		return;
	std::stack<TreeNode *> nstack1, nstack2;
	nstack1.push(root);
	while (!nstack1.empty()) {
		TreeNode *temp = nstack1.top();
		nstack1.pop();
		nstack2.push(temp);
		if (temp->left)
			nstack1.push(temp->left);
		if (temp->right)
			nstack1.push(temp->right);
	}
	while (!nstack2.empty())
	{
		TreeNode *p=nstack2.top();
		nstack2.pop();

		TreeNode *n = p->right;
		p->right = p->left;
		p->left = n;
		
	}

	
}



int main()
{
	TreeNode *tn = &TreeNode(2);

}