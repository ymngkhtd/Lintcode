#include<iostream>
#include<vector>
#define NULL 0
using namespace std;

//链表节点
class Node
{
public:
	int Key, Val;
	Node *next;
	Node(int key, int val)
	{
		this->Key = key;
		this->Val = val;
		this->next = NULL;
	}


};

class LRUCache {
public:
	/*
	* @param capacity: An integer
	*/
	LRUCache(int capacity) {
	// do intialization if necessary
	num = capacity;
}

	  /*
	  * @param key: An integer
	  * @return: An integer
	  */
	  int get(int key) {
		  // write your code here
		  if (Fir == NULL)           //链表为空
		  {
			  return -1;
		  }
		 
		  int i = visit(key);
		  return i;
	  }

	  /*
	  * @param key: An integer
	  * @param value: An integer
	  * @return: nothing
	  */
	  void set(int key, int value) {
		  // write your code here
		  if (Fir == NULL)             
		  {
              Fir = new Node(key, value);
			  Nnum = 1;
			  return;
		  }
		  Node *nd = this->Fir;
		  while (true)
		  {
			  if (nd->Key == key)               //已有重复Key
			  {
				  nd->Val = value;
				  visit(key);
				  return;
			  }
			  if (nd->next != NULL)
				  nd = nd->next;
			  else
				  break;
		  }

		  if (Nnum == num)                     
		  {
			  if (num == 1)                 //只有一个项
			  {
				  Fir->Key = key;
				  Fir->Val = value;
				  return;
			  }
			  else
			  {
				  Node *nd1 = Fir;
				  Fir = Fir->next;
				  nd1->next = NULL;
			  }

		  }
		  else
		  {
			  Nnum++; 
		  }
		  nd->next = new Node(key, value);
		
	  }

	  int visit(int key)
	  {
		  Node *nd = Fir;
		  if (nd->Key == key)     //如果第一项为要找的那项
		  {
			  if (nd->next != NULL)          //有多项
			  {
				  while (nd->next != NULL)
				  {
					  nd = nd->next;
				  }
				  nd->next = Fir;
				  Fir = Fir->next;
				  nd->next->next = NULL;
				  return nd->next->Val;
			  }
			  else
			  {
				  return nd->Val;
			  }
		  }
		  Node *nd1 = NULL;                            //记录找到的那项
		  while (nd->next != NULL)
		  {
			  if (nd->next->Key == key)
			  {
				  if (nd->next->next == NULL)      //如果找到的项是最后一项	
					  return nd->next->Val;
				  nd1 = nd->next;
				  nd->next = nd1->next;
				  nd1->next = NULL;

			  }

			  nd = nd->next;

		  }
		  if (nd1 != NULL)
		  {
			  nd->next = nd1;             //最后一项为nd1
			  return nd1->Val;
		  }
		  return -1;
	  }
private:
	int num;             //维护的链表长度
	int Nnum;            //链表现长
	Node *Fir;           //链表起始结点
};


int main()
{
	vector<int> vec;
	LRUCache lruc = LRUCache(1);


	lruc.set(2,1);
	vec.push_back(lruc.get(2));
	lruc.set(3, 2);
	vec.push_back(lruc.get(2));
	vec.push_back(lruc.get(3));

	return 0;
}