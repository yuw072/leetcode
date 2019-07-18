// Add Binary.cpp : https://leetcode-cn.com/problems/add-binary/
//2019.7.17

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int asize = a.size();
		int bsize = b.size();
		int size;
		int tempsize;
		string result;
		string temp;
		if (asize > bsize)
		{
			size = asize;
			tempsize = bsize;
			result = a;
			temp = b;
		}
		else
		{
			size = bsize;
			tempsize = asize;
			result = b;
			temp = a;
		}
		char add = '0';//进位标志
		int i = size-1;
		int j = tempsize-1;
		string temp0;
		do
		{
			if (j == -1) { j = 0; }
			cout << i <<j<< endl;
			temp0 = addBit(result[i],temp[j],add);
			result[i] = temp0[0];
			add = temp0[1];
			if (j == 0)
			{
				temp[0] = '0';
			}
			i--;
			j--;
			if (i == -1) { break; }
		} while (add=='1'||j>=0);
		if (add == '1')return '1' + result;
		return result;
	}
	string addBit(char a, char b,char c) {
		if (a == '0' && b == '0' && c == '0') { return "00"; }
		if (a == '0' && b == '0' && c == '1') { return "10"; }
		if (a == '0' && b == '1' && c == '0') { return "10"; }
		if (a == '0' && b == '1' && c == '1') { return "01"; }
		if (a == '1' && b == '0' && c == '0') { return "10"; }
		if (a == '1' && b == '0' && c == '1') { return "01"; }
		if (a == '1' && b == '1' && c == '0') { return "01"; }
		if (a == '1' && b == '1' && c == '1') { return "11"; }
		//前面为值，后面为进位
		return "00";
	}
};

int main()
{
	string a = "11";
	string b = "110";
	Solution test;
	cout << test.addBinary(a, b) << endl;
}