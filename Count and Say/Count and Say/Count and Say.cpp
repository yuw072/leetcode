// Count and Say.cpp : https://leetcode-cn.com/problems/count-and-say/
//2019.7.15

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string lastone = countAndSay(n - 1);
		int size =lastone.size();
		char temp = lastone[0];
		string result = "0";
		int j = 0;//result的操作符
		int i = 0;//遍历lastone的操作符
		for (i; i < size; i++)
		{
			if (temp == lastone[i])
			{//相同就数量加一
				result[j] = char(int(result[j]) + 1);
				if (i == size - 1) { result += lastone[i]; }
			}
			else
			{//不同就结束计数，加上该数字，再加新数字的数量1
				result += lastone[i-1];
				result += "1";
				if (i == size - 1) { result += lastone[i]; }
				j += 2;
			}
			temp = lastone[i];
		}
		return result;
	}
};

int main()
{
    Solution test;
	for (int i = 1; i <= 5; i++)
	{
		cout << test.countAndSay(i) << endl;
	}

}
//笔记
//多想多试
