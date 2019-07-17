// Search Insert Position.cpp : https://leetcode-cn.com/problems/search-insert-position/
//2019.7.14

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (target <= nums[i]) { return i; }
		}
		return size;
	}
};

int main()
{
	vector<int> nums = { 1,3,5,6 };
	int target = 5;
	Solution test;
	cout << test.searchInsert(nums, target) << endl;
}
//继续手撕