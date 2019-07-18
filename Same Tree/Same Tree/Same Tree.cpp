// Same Tree.cpp : https://leetcode-cn.com/problems/same-tree/
//2019.7.18

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) { return 1; }
		if (p == NULL && q != NULL) { return 0; }
		if (p != NULL && q == NULL) { return 0; }
		if (p->left == NULL && q->left != NULL) { return 0; }
		if (q->left == NULL && p->left != NULL) { return 0; }
		if (p->right == NULL && q->right != NULL) { return 0; }
		if (q->right == NULL && p->right != NULL) { return 0; }
		if (p->val == q->val) 
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return 0;
	}
};

int main()
{
	TreeNode p(12);
	TreeNode q(12);
	p.right = new TreeNode(60);
	q.right = new TreeNode(72);
	Solution test;
	cout << test.isSameTree(&p, &q) << endl;
}
