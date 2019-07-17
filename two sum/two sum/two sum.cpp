// two sum.cpp :https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-gpe3dbjds1/
//2019.7.12
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i,j;
		for (i = 0; i < (nums.size() - 1); i++)
		{
			for (j = i+1; j < nums.size(); j++)
			{
				if (int(nums[i] + nums[j]) == target)
				{
					return { i,j };
				}
			}
		}
		return { -1,-1};
	};
};

int main()
{
	int nums_size = 4;//输入数组大小
	vector<int> nums(nums_size);
	vector<int> twoSum(2);//结果
	int* temp = new int[nums_size] { 2, 7, 11, 15 };//动态数组暂存输入数字组
	for (int i = 0; i < nums_size; i++)//转至vector
	{
		nums[i] = temp[i];
	}
	int target = 9;//目标和
	Solution test;//初始化类
	twoSum = test.twoSum(nums, 9);
	cout << twoSum[0] <<","<<twoSum[1] <<endl;
	return 0;
}
/*
笔记：
1.注意无输入参数的函数后写括号
2.复习动态数组，vector，class等
3.debug时注意类型等问题
*/
