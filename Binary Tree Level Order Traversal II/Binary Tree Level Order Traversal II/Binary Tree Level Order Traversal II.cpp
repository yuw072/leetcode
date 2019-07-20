// Binary Tree Level Order Traversal II.cpp : https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
//2019.7.20

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<TreeNode*>>temp;//放所有TreeNode
		vector<TreeNode*>temp_level;//暂存每层
		int Depth = maxDepth(root);
		temp_level.push_back(root);
		temp.push_back(temp_level);
		for (int i = 1; i < Depth; i++)//i为上层标，处理每个i下一层入容器
		{
			temp_level.clear();
			for (int j = 0; j < temp[i-1].size(); j++)
			{
				if (temp[i-1][j]->left != NULL) { temp_level.push_back(temp[i-1][j]->left); }
				if (temp[i-1][j]->right != NULL) { temp_level.push_back(temp[i-1][j]->right); }
			}
			temp.push_back(temp_level);
		}
		vector<vector<int>> result;//所有
		vector<int> result_level;//每层
		for (int i = Depth-1; i>=0; i--)//i为层标
		{
			result_level.clear();
			for (int j = 0; j < temp[i].size(); j++)
			{
				result_level.push_back(temp[i][j]->val);
			}
			result.push_back(result_level);
		}
		return result;
	}
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
	void show(TreeNode* root) {
		vector<vector<int>> temp;
		temp = levelOrderBottom(root);
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp[i].size(); j++)
			{
				cout << temp[i][j] << ",";
			}
			cout << endl;
		}
	}
};

int main()
{
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);
	Solution test;
	test.show(&root);
}

//笔记
//以后二叉树的层序遍历记得使用队列进行每层的存储
//从根节点入队开始，对队头的子节点进行入队并遍历本节点后出队，直至队列为空