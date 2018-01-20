#include<iostream>
#include<vector>
#define NULL 0
using namespace std;
//��vectorʵ�ֵ�ջ��ά������vector
class MinStack {
public:

  
	/*
	* @param a: An integer
	*/
	MinStack(int a) {
		// do intialization if necessary
		Msize = a;
		
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		// write your code here

		int Nsize = vec.size();   
		if (Nsize<=Msize)
		{
			vec.push_back(number);
			if(vecmin.size()==0)
				vecmin.push_back(number);
			else
			{
				int Nmin = vecmin.back();
				if (Nmin>number)
					vecmin.push_back(number);
				else
					vecmin.push_back(Nmin);

			}
			
		}

	}

	/*
	* @param a: An integer
	* @return: An integer
	*/
	int pop(int a) {
		// write your code here
		if (vec.size() == 0)
			return NULL;
		int num=vec.back();
		vec.pop_back();
		vecmin.pop_back();
		return num;
	}

	/*
	* @param a: An integer
	* @return: An integer
	*/
	int min(int a) {
		// write your code here
		if (vec.size() == 0)
			return NULL;
		return vecmin.back();
	}

	//int getsize()
	//{
	//	return vec.size();
	//}

private:
	int Msize;                                //ά����ջ�Ĵ�С
	vector<int> vec;                         //ά����Ԫ�ؼ�������
	vector<int> vecmin;                     //ά������СֵԪ�ؼ�������
};

int main()
{
	MinStack ms = MinStack(5);
	ms.push(3);
	ms.push(5);
	ms.push(1);
	//int a = ms.getsize();
	return 0;
}