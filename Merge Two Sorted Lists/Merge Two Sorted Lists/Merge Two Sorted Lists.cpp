// Merge Two Sorted Lists.cpp : https://leetcode-cn.com/problems/merge-two-sorted-lists/
//2019.7.14

#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) { return l2; }
		if (l2 == NULL) { return l1; }
		ListNode* temp=new ListNode(l2->val);
		if (l1->val < l2->val)
		{
			temp->val = l1->val;
			l1 = l1->next;
		}
		else
		{
			l2 = l2->next;
		}//先选个小的放上
		do
		{
			if (l1 == NULL && l2 == NULL) { break; }
			if (l1 == NULL) { InsertNumberToEnd(temp, l2->val); l2 = l2->next; continue; }
			if (l2 == NULL) { InsertNumberToEnd(temp, l1->val); l1 = l1->next; continue; }
			if (l1->val < l2->val)
			{
				InsertNumberToEnd(temp, l1->val);
				l1 = l1->next;
			}
			else
			{
				InsertNumberToEnd(temp, l2->val);
				l2 = l2->next;
			}
		} while (1);
		return temp;
	}
	void InsertNodeToBehind(ListNode* l1, ListNode* l2)//l2插在l1后面
	{
		if (l1->next == NULL) { l1->next = l2; }
		else
		{
			ListNode* temp;
			temp = l1->next;
			l1->next = l2;
			l2->next = temp;
		}
	}
	ListNode* InsertNumberToEnd(ListNode* l1, int x)//x插在l1最后并返回最后一个指针
	{
		ListNode* temp;
		temp = l1;
		do
		{
			if (temp->next != NULL) { temp = temp->next; }
			else { break; }
		} while (1);
		InsertNodeToBehind(temp, new ListNode(x));
		return temp;
	}
	void ShowList(ListNode* l1)
	{
		ListNode* temp;
		temp = l1;
		do
		{
			cout << temp->val << "  ";
			temp = temp->next;
		} while (temp!= NULL);
		cout << endl;
	}
};

int main()
{
	Solution test;
	ListNode l1(1);
	ListNode l2(1);
	test.InsertNumberToEnd(&l1, 2);
	test.InsertNumberToEnd(&l1, 4);
	test.InsertNumberToEnd(&l2, 3);
	test.InsertNumberToEnd(&l2, 4);
	test.ShowList(&l1);
	test.ShowList(&l2);
	test.ShowList(test.mergeTwoLists(&l1, &l2));
}
/*
笔记
1.注意函数内部需要传出的要用new新建，不然好像会被清除
2.可以多建函数
3.重写永远比debug简单
*/