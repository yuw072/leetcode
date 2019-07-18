// Remove Duplicates from Sorted List.cpp : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
//2019.7.18

#include <iostream>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) { return head; }
		if (head->next == NULL) { return head; }
		ListNode* temp = head;
		do
		{
			if (head->val == head->next->val)
			{
				DeleteNextListNode(head);
			}
			else { head = head->next; }
		} while (head->next != NULL);
		return temp;
	}
	void DeleteNextListNode(ListNode* l1)//删除l1下一个节点
	{
		l1->next = l1->next->next;
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
		} while (temp != NULL);
		cout << endl;
	}
};

int main()
{
	Solution test;
	ListNode l1(1);
	test.InsertNumberToEnd(&l1, 1);
	test.InsertNumberToEnd(&l1, 2);
	test.ShowList(&l1);
	test.ShowList(test.deleteDuplicates(&l1));
}