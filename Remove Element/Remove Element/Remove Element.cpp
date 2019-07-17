// Remove Element.cpp : https://leetcode-cn.com/problems/remove-element/
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums,int val) {
		int length = 0;
		int size = nums.size();
		if (size == 0) { return 0; }
		for (int i = 0; i < size; i++)
		{
			if (nums[i] != val)
			{
				nums[length++] = nums[i];
			}
		}
		return length;
	}
};
int main()
{
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	Solution test;
	int length = test.removeElement(nums, val);
	for (int i = 0; i < length; i++) {
		cout<<(nums[i])<<" ";
	}
	cout << endl;
}
//继续手撕

