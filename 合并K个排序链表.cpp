// �ϲ�K����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};


//˼·�������ַ�����
//1.��ָ��vector���������ι鲢����󷵻�����ͷ(K - 1�ι鲢)
//2.�����鲢���ٽ��鲢������������鲢�����η�����Ч�ʣ�
//3.������С�ѵ����ʣ��Ѷ�Ԫ��Ϊ������СԪ�أ���ÿ������ͷԪ�ط�����ڣ�Ȼ������ÿ��ȡ����С���Ǹ�Ԫ�ؼ����������ս���������У�Ȼ���ȡ��Ԫ�ص���һ��Ԫ���ټ�����У��´��ԴӶ���ȡ����С��Ԫ������ͬ�Ĳ������Դ����ƣ�ֱ������û��Ԫ���ˡ�



/***************** �鲢˼�� *****************/
ListNode *mergeKLists(vector<ListNode *> &lists) {
	// write your code here
	int n = lists.size();
	if (n == NULL)
	{
		ListNode *nu = NULL;
		return nu;

	}
		
	ListNode *Rel = lists[0];
	for (int i = 1;i < n;i++)
	{
		Rel=Merge(Rel, lists[i]);                   //�鲢K-1�Σ�Ч�ʽϵ�
	}
	return Rel;

	//int gap = 1;
	//while (gap<n)
	//{
	//	for (int i = 0;i + gap<n;i += 2 * gap)
	//	{
	//		lists[i] = Merge(lists[i], lists[i + gap]);                   //���Ч�ʣ������ϲ�
	//	}
	//	gap *= 2;
	//}
	//return lists[0];

}

ListNode *Merge(ListNode *fir, ListNode *sec)
{
	if (fir == NULL)
		return sec;
	else if (sec == NULL)
		return fir;

	ListNode *res = NULL;

	if (fir->val <= sec->val)
	{
		res = fir;
		res->next = Merge(fir->next, sec);
	}
	else
	{
		res = sec;
		res->next = Merge(fir, sec->next);
	}
	return res;
}
/*                                                              */


/************************** ��С��ʵ�� *********************************/
struct cmp {
	bool operator () (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};
ListNode *mergeKListsheap(vector<ListNode *> &lists)
{
	priority_queue<ListNode*, vector<ListNode*>, cmp> q;
	for (int i = 0; i < lists.size(); ++i) {
		if (lists[i])
			q.push(lists[i]);
	}

	ListNode *head = NULL, *pre = NULL, *tmp = NULL;
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		if (!pre) head = tmp;               //preΪNULL
		else pre->next = tmp;
		pre = tmp;
		if (tmp->next) q.push(tmp->next);
	}
	return head;
}




int main()
{
	ListNode *ln = &ListNode(0);
	vector<ListNode *> list;
	//list.push_back(ln);
	mergeKLists(list);

    return 0;
}

