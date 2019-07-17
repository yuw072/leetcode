// Length of Last Word.cpp : https://leetcode-cn.com/problems/length-of-last-word/
//2019.7.17

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int size = s.size();
		if (s.find(' ') == -1) { return size; }
		if (size - s.find_last_of(' ') - 1 == 0) { return lengthOfLastWord(s.substr(0, s.size() - 1)); }
		return size - s.find_last_of(' ')-1;
	}
};

int main()
{
	string s = "asaa ";
	Solution test;
	cout << test.lengthOfLastWord(s) << endl;
}