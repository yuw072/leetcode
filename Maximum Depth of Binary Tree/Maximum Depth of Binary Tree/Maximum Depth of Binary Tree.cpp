// Maximum Depth of Binary Tree.cpp : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
	int maxDepth(TreeNode* root) {
		if (root == NULL) { return 0; }
		else 
		{
			int left = maxDepth(root->left);
			int right = maxDepth(root->right);
			if (left > right) { return 1 + left; }
			else { return 1 + right; }
		}
	}
};

int main()
{

}

