// Plus One.cpp : https://leetcode-cn.com/problems/plus-one/
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int size = digits.size();
		int i = 0;
		do
		{
			if (digits[size - 1 - i] != 9) 
			{
				digits[size - 1 - i] += 1; return digits; 
			}
			digits[size - 1 - i] = 0;
			i++;
		} while (i < size);
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};

int main()
{
	vector<int> digits = { 1,2,3,4 };
	Solution test;
	vector<int> temp = test.plusOne(digits);
	cout << temp[0]<< temp[1]<< temp[2]<<temp[3] << endl;
}

