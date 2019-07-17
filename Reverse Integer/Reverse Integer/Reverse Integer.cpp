// Reverse Integer.cpp :https://leetcode-cn.com/problems/reverse-integer/
//2019.7.13

#include <iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int ispositive = 2*(x > 0)-1;//1正-1负
		if (x == -int(2147483648)) { return 0; }
		else { x = ispositive * x; }//归正
		int isoverflow = 0;
		int y = x;//对x进行处理的中转
		int result = 0;
		int temp[10] = { 0 };//2^32-1为10位数,存各位数字,从最后一位开始存
		int result_temp[10] = { 0 };
		int max[10] = { 2,1,4,7,4,8,3,6,4,8 };//2^31的各位数字，用作overflow的判定
		int i = 0;//定位数
		for (i; i < 10; i++)
		{
			x = x / 10;
			temp[i] = y - 10 * x;
			y = x;
			if (x == 0)
			{
				break;
			}
		}//i+1位数字
		
		if (i == 9)
		{
			for (int m = 0; m < 10; m++)
			{
				int ism9 = 0;
				if (m == 9) { ism9 = 1; }
				if (temp[m] > (max[m] - ism9 * (ispositive < 0))) { return 0; }//正比2^32负比2^32-1
				else if (temp[m] == (max[m] - ism9 * (ispositive < 0))) { }
				else { break; }
			}
		}
		int tentosomething = 1;//位权
		for (int j = i; j >= 0; j--)
		{
			result += tentosomething * temp[j];
			tentosomething *= (6+(4*(2*(j>0)-1)));
		}
		return ispositive * result;
	}
};

int main()
{
	Solution test;
	int x = -1234567890;
	int result = test.reverse(x);
	cout << result << endl;
	return 0;
}
/*
笔记：
1.一切可能导致overflow的运算都要先检验再进行，注意正负不对称问题
2.特殊值可以考虑手动剔除
*/