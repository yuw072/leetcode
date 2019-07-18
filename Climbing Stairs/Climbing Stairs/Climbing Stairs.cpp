// Climbing Stairs.cpp : https://leetcode-cn.com/problems/climbing-stairs/
//2019.7.18

#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) { return 1; }
		if (n == 2) { return 2; }
		int one = 1;
		int two = 2;
		int result=2;
		for (int i = 3; i <= n; i++)
		{
			two = result;
			result += one;
			one = two;
		}
		return result;
	}
};

int main()
{
	int n = 5;
	Solution test;
	cout << test.climbStairs(n) << endl;
}
//n=44时递归会超时，需要使用非递归算法