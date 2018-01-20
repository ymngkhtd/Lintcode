// 两个链表的交叉.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode * ListMaker(vector<int> &a)
//将vec中元素转化为链表
{
	ListNode *res= new ListNode(a[0]);
	ListNode *wei = res;
	for (int i = 1;i < a.size(); i++)
	{
		
		wei->next = new ListNode(a[i]);
		wei = wei->next;
	}
	return res;
}

ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
	// write your code here
	if (headA==0||headB==0)                  //有空链表
		return 0;
	ListNode *a=headA, *b=headB,*c,*d,*res;
	while (a != 0 && b != 0)                   //a,b同时从头走，某一方为空则停止
	{
		a = a->next;
		b = b->next;
	}
	a == 0 ? d = headB, c = b,res=headA : c = a, d = headA,res=headB;    //如果a为空则说明a短，
	                                                                     //用d记录较长一方的链表头，
	                                                                     //c记录当较短一方走到尾部null时，较长的一方走到了哪
	                                                                     //res为返回值，这里记录较短一方的链表头

	while (c != 0)                     //d，c同时走，上一步记录的c走到链表尾部null时，d应该已走了两表长度差的步数
	{
		d = d->next;
		c = c->next;
	}

	while (d->val!=res->val)           //d与记录较短一方表头的res同时走，一定同时到达表尾null
	{
		d = d->next;
		res = res->next;

	}
	return res;
}
int main()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	vector<int> vec2 = { 7,8,9,10,11,12,13 };
	ListNode *a = ListMaker(vec);
	ListNode *b = ListMaker(vec2);
	getIntersectionNode(a, b);
    return 0;
}

