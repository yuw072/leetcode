// Longest Common Prefix.cpp :https://leetcode-cn.com/problems/longest-common-prefix/
//2019.7.13

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		vector<string> temp = strs;
		int size = strs.size();
		if (size == 0) { return ""; }
		int min_length = strs[0].size();
		for (int i = 1; i < size; i++)
		{
			if (strs[i].size() > min_length) { min_length = strs[i].size(); }
		}
		string result = "";
		for (int j = 0; j < min_length; j++)//j为相同字符数
		{
			string temp0(temp[0],0,j+1);//存第一个字符串里要比较的
			for (int m = 1; m < size; m++)
			{
				string temp1(temp[m],0, j + 1);
				if (temp0 != temp1) { return result; }
			}
			result = temp0;
		}
		return result;
	}
};

int main()
{
	vector<string> strs = { "abc","abca" };
	Solution test;
	cout << test.longestCommonPrefix(strs) << endl;
	return 0;
}
