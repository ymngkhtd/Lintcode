// 合并K个排序链表.cpp : 定义控制台应用程序的入口点。
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


//思路：（三种方法）
//1.将指针vector遍历，依次归并，最后返回链表头(K - 1次归并)
//2.两两归并，再将归并结果进行两两归并（分治法提升效率）
//3.利用最小堆的性质，堆顶元素为堆内最小元素，将每组链表头元素放入堆内，然后我们每次取出最小的那个元素加入我们最终结果的链表中，然后把取出元素的下一个元素再加入堆中，下次仍从堆中取出最小的元素做相同的操作，以此类推，直到堆中没有元素了。



/***************** 归并思想 *****************/
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
		Rel=Merge(Rel, lists[i]);                   //归并K-1次，效率较低
	}
	return Rel;

	//int gap = 1;
	//while (gap<n)
	//{
	//	for (int i = 0;i + gap<n;i += 2 * gap)
	//	{
	//		lists[i] = Merge(lists[i], lists[i + gap]);                   //提高效率，两两合并
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


/************************** 最小堆实现 *********************************/
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
		if (!pre) head = tmp;               //pre为NULL
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

