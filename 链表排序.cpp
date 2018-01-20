#include<iostream>
#include<vector>	
using namespace std;
#define NULL 0

 class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
        this->next = NULL;
     }
 };



class Solution {
public:
	/*
	* @param head: The head of linked list.
	* @return: You should return the head of the sorted linked list, using constant space complexity.
	*/
	//归并排序的方法
	ListNode * sortList(ListNode * head) {
		// write your code here
		if (head == NULL || head->next == NULL)      //空链表或只有一个元素
			return head;

		ListNode *fir = head, *sec = head;          //需要两个指针找到链表的中间结点
		while (sec->next != NULL&&sec->next->next != NULL)
		{
			fir = fir->next;
			sec = sec->next->next;                           //第二个指针移动第一个指针两倍
		}
		sec = fir;
		fir = fir->next;
		sec->next = NULL;

		return(Merge(sortList(head), sortList(fir)));      

	}
	//两个需要归并的数组起始,递归过程
	ListNode * Merge(ListNode* ln1, ListNode* ln2)
	{
		if (ln1 == NULL)
			return ln2;
		else if (ln2 == NULL)
			return ln1;
		ListNode *res = NULL;
		if (ln1->val <= ln2->val)
		{
			res = ln1;
			res->next = Merge(ln1->next, ln2);
		}
		else
		{
			res = ln2;
			res->next = Merge(ln1, ln2->next);
		}
		return res;
	}
};