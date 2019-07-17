// Implement strStr().cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) { return 0; }
		if (haystack.size() == 0) { return -1; }
		string temp;
		for (int i=0; i < haystack.size(); i++)
		{
			if (temp.assign(haystack, i, needle.size()) == needle) { return i; }
		}
		return -1;
	}
};

int main()
{
	string haystack = "hello";
	string needle = "ll";
	Solution test;
	cout << test.strStr(haystack, needle)<< endl;
}
//笔记
//多利用库函数提升效率