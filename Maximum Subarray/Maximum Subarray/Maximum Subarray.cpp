// Maximum Subarray.cpp : https://leetcode-cn.com/problems/maximum-subarray/
//2019.7.16

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		if (size == 1) { return nums[0]; }
		int max = INT_FAST32_MIN;
		int temp = INT_FAST32_MIN;
		for (int i = 0; i < size; i++)
		{
			temp = nums[i];
			if (temp > max) { max = temp; }
			for (int j = i+1; j < size; j++)
			{
				temp += nums[j];
				if (temp > max) { max = temp; }
			}
		}
		return max;
	}
};

int main()
{
	vector<int> nums = { -2,-1};
	Solution test;
	cout << test.maxSubArray(nums) << endl;
}