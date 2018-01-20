// ��������Ľ���.cpp : �������̨Ӧ�ó������ڵ㡣
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
//��vec��Ԫ��ת��Ϊ����
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
	if (headA==0||headB==0)                  //�п�����
		return 0;
	ListNode *a=headA, *b=headB,*c,*d,*res;
	while (a != 0 && b != 0)                   //a,bͬʱ��ͷ�ߣ�ĳһ��Ϊ����ֹͣ
	{
		a = a->next;
		b = b->next;
	}
	a == 0 ? d = headB, c = b,res=headA : c = a, d = headA,res=headB;    //���aΪ����˵��a�̣�
	                                                                     //��d��¼�ϳ�һ��������ͷ��
	                                                                     //c��¼���϶�һ���ߵ�β��nullʱ���ϳ���һ���ߵ�����
	                                                                     //resΪ����ֵ�������¼�϶�һ��������ͷ

	while (c != 0)                     //d��cͬʱ�ߣ���һ����¼��c�ߵ�����β��nullʱ��dӦ�������������Ȳ�Ĳ���
	{
		d = d->next;
		c = c->next;
	}

	while (d->val!=res->val)           //d���¼�϶�һ����ͷ��resͬʱ�ߣ�һ��ͬʱ�����βnull
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

