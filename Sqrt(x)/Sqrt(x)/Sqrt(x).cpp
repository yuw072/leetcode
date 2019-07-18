// Sqrt(x).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//2019.7.18

#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <=1 ) { return x; }
		int temp = x / 2;
		int a = 0;//查找下限
		int b = x;//查找上限
		do
		{
			if (long(temp) *long(temp) > x)
			{ 
				b = temp;
				temp = (a + b) / 2;
			}
			else if (long(temp) * long(temp)==x) { return temp; }
			else
			{
				a = temp;
				temp = (a + b) / 2;
			}
		} while ((b - a) > 1);
		return a;
	}
};

int main()
{
	int x = 90;
	Solution test;
	cout << test.mySqrt(x) << endl;
}

