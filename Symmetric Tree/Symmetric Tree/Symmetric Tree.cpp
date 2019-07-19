// Symmetric Tree.cpp : https://leetcode-cn.com/problems/symmetric-tree/submissions/
//2019.7.19

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) { return 1; }
		return isSameTree(root->left, root->right);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) { return 1; }
		if (p == NULL && q != NULL) { return 0; }
		if (p != NULL && q == NULL) { return 0; }
		if (p->val == q->val)
		{
			return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
		}
		return 0;
	}
};

int main()
{
	Solution test;
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(2);
	cout << test.isSymmetric(&root) << endl;
}

