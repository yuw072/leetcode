// Remove Duplicates from Sorted Array.cpp : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
//2019.7.14

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int length = 1;
		int size = nums.size();
		if (size == 0) { return 0; }
		int temp = nums[0];
		for (int i = 1; i < size; i++)
		{
			if (nums[i] != temp)
			{
				nums[length++] = nums[i];
				temp = nums[i];
			}
		}
		return length;
	}
};

int main()
{
	vector <int> nums = {0,0,1,1,2,2,3,3};
	Solution test;
	int length = test.removeDuplicates(nums);
	for (int i = 0; i < length; i++) {
		cout<<(nums[i])<<" ";
	}
	cout << endl;
}

//终于有个手撕的找回自信了ggwp