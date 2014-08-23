/*************************************************************************
       File: reverse_linked_list_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:57:29

Reverse Linked List II 
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
************************************************************************/

#include "tools.h"

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		ListNode *tail = NULL, *cur = head;
		for(int i = 1; i < m; i++)			// cur定位到m
		{
			tail = cur;						// tail之后的n-m+1个元素将逆序
			cur = cur->next;
		}

		for(int i = m; i < n; i++)
		{
			ListNode *next = cur->next;
			if(tail)						// m != 1
			{
				cur->next = next->next;		
				next->next = tail->next;
				tail->next = next;
			} else {						// m = 1
				cur->next = next->next;
				next->next = head;
				head = next;
			}

		}

		return head;
	}
};

void print(ListNode *itr)
{
	while(itr)
	{
		cout<<itr->val<<"->";
		itr = itr->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	head = (new Solution())->reverseBetween(head, 1,5);
	
	print(head);

	return 0;
}
