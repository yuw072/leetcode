// Roman to Integer.cpp : https://leetcode-cn.com/problems/roman-to-integer/
//2019.7.13

#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int size = s.size();
		int result = 0;
		int* nums = new int[size];
		int i = 0;
		for (i; i < size; i++)
		{
			switch (s[i])
			{
				case 'I' : nums[i] = 1; break;
				case 'V' : nums[i] = 5; break;
				case 'X' : nums[i] = 10; break;
				case 'L' : nums[i] = 50; break;
				case 'C' : nums[i] = 100; break;
				case 'D' : nums[i] = 500; break;
				case 'M' : nums[i] = 1000; break;
				default:nums[i] = 0; break;
			}
		}
		i = 0;
		for (i; i < size-1; i++)
		{
			result += nums[i] * (2 * (nums[i] >= nums[i + 1]) - 1);
		}
		result += nums[size - 1];
		return result;
	}
};

int main()
{
	string s = "LVIII";
	Solution test;
	cout << test.romanToInt(s) << endl;
}
//笔记：
//1.swtich里要写break
//2.再复习动态数组