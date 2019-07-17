// Valid Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//2019.7.13

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int size = s.size();
		if ((size % 2) == 1) { return 0; }
		if (size == 0) { return 1; }
		if (size == 2) { return isValid_two(s); }
		int sign = 0;
		for (int j = 0; j < (size - 1); j++)
		{
			size = s.size();
			if (s.size() == 2) { break; }
			if (isValid_two(s.substr(j, 2)))
			{
				s.erase(j + s.begin());
				s.erase(j + s.begin());
				j = j-1;
				sign = 1;
			}
			if ((sign == 0) && (j == size - 2)) { return 0; }
		}
		return isValid(s);
	}
	bool isValid_two(string s)
	{
		int temp1 = (s[0] == '(') && (s[1] == ')');
		int temp2 = (s[0] == '[') && (s[1] == ']');
		int temp3 = (s[0] == '{') && (s[1] == '}');
		return temp1 + temp2 + temp3;
	};
};


int main()
{
	string s = "[(])";
	Solution test;
	cout << test.isValid(s) << endl;
}

/*笔记：
1.注意函数递归时检查无尽循环的问题
2.注意复杂时可新建其他函数
3.函数可以考虑重构
4.注意可以利用return
5.注意写不出来的时候去看看风景
6.注意改不出来的时候可以放弃原代码，重新写一份，这样可以更快进入自闭状态
*/