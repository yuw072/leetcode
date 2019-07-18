// Merge Sorted Array.cpp : https://leetcode-cn.com/problems/merge-sorted-array/
//2019.7.18

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) { return; }
		if (m == 0) { nums1 = nums2; return; }
		int min;
		if (nums1[0] > nums2[0]) { min = nums2[0]; }
		else { min = nums1[0]; }
		do
		{
			cout << m << "," << n << endl;
			if (m > 0 && n > 0)
			{
				if (nums1[m - 1] > nums2[n - 1])
				{
					cout << 1 << "," << m + n - 1 << ":" << nums1[m + n - 1] << "->" << nums1[m - 1] << endl;
					nums1[m + n - 1] = nums1[m - 1];
					m--;
				}
				else
				{
					cout << 2 << "," << m + n - 1 << ":" << nums1[m + n - 1] << "->" << nums2[n - 1] << endl;
					nums1[m + n - 1] = nums2[n - 1];
					n--;
				}
			}
			else if (n > 0)
			{
				cout << 3 << "," << n << ":" << nums1[n-1] << "->" << nums2[n-1] << endl;
				nums1[n-1] = nums2[n-1];
				n--;
			}
			else { cout << 4 << endl; break; }
		} while (n>=0||m>=0);
		nums1[0] = min;
	}
};

int main()
{
	vector<int> nums1 = { 2,0 };
	vector<int> nums2 = { 1 };
	int m = 1;
	int n = 1;
	Solution test;
	for (int i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i] << ",";
	}
	cout << endl;
	for (int i = 0; i < nums2.size(); i++)
	{
		cout << nums2[i] << ",";
	}
	cout << endl;
	test.merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i] << ",";
	}
	cout << endl;
}
