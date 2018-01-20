// ��ӽ�������֮��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;




/*
* @param numbers: Give an array numbers of n integer
* @param target: An integer
* @return: return the sum of the three integers, the sum closest target.
*/
int threeSumClosest(vector<int> &numbers, int target) {
	// write your code here
	int nb = numbers.size();
	if (nb<3)                     //����������������
		return 0;

	sort(numbers.begin(), numbers.end());                       //�ȴ�С��������
	int cha = INT_MAX;                    //������¼��С��ֵ
	int res = 0;                          //���·���ֵ
	for (int i = 0;i < nb;i++)         //����vector
	{                                  //iΪ��һ�������
		int j = i + 1;                 //jΪ�ڶ��������
		int k = nb - 1;                //kΪ�����������
		
		while (j < k)                 //ѭ��������jС��k
		{
			if (cha>abs(numbers[i] + numbers[j] + numbers[k] - target))        //�������ѭ����������target��ֵ�ľ���ֵ��֮ǰ��¼����С��ֵҪС(���ӽ�target)
			{
				cha = abs(numbers[i] + numbers[j] + numbers[k] - target);      //���²�ֵ
				res = numbers[i] + numbers[j] + numbers[k];                    //���·���ֵ
			}
			if (numbers[i] + numbers[j] + numbers[k] >target)                  //��������ʹ���target
			{
				--k;             
			}
			else if (numbers[i] + numbers[j] + numbers[k] < target)            //���������С��target
			{
				++j;            
			}
			else
				return target;            //���õ���target���򷵻�
		}
	}
	return res;
}

int main()
{
	vector<int> te = { -2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5 };
	threeSumClosest(te, 45);
    return 0;
}

