// �����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>	
#include<vector>
#include<algorithm>
using namespace std;

// bool reten(int &a,int &b)
//�ݹ�ķ�������ջ
//{
//	
	//bool biger = true;     //����ֵ��tureΪa��bǰ��false���෴
	//int ax = a;
	//int bx = b;
	//int ay = 0;            //��������a����
	//int by = 0;            //����b����
	//int i = 1;             //��¼����ʮ����λ
	//int j = 1;             //��¼����ʮ����λ
	//while (ax / 10)
	//{

	//	ay += ax % 10 * i;
	//	ax /= 10;
	//	i *= 10;
	//}
	//while (bx / 10)
	//{
	//	by += bx % 10 * j;
	//	bx /= 10;
	//	j *= 10;
	//}
//	if (ax == bx)                 //���a����λ��b����λ���
//		biger = reten(ay, by);       //��������Ϊ���������ж�
//	else if (ax < bx)
//		return false;
//	else
//		return true;
//	return biger;
//}

//bool reten(int &a, int &b)
//{
//	
//}
bool cmp(int &a, int &b)
//����ԭ��
{
	if (!a)
		return false;
	if (!b)
		return true;

	if (a == b)
		return false;
	int ax = a;            //����ÿ��ѭ���жϵ�a��ʮ�������λ
	int bx = b;            //����ÿ��ѭ���жϵ�b��ʮ�������λ
	int ay = 0;            //��������a����
	int by = 0;            //����b����
	int i = 1;
	int j = 1;
	do
	{
		if (!(ax==a&&bx==b))         //���״�ѭ��
		{
			if(i!=1)                 //���a�в�ֹһλʮ����λ
			ax = ay;                 //����ѭ�����ϴ�ѭ�����������в���
			if(j!=1)                 //���ֻ��һλʮ����λ���򱾴��Բ�����һ��ѭ������
			bx = by;
		}
		 if(ax==bx)                  //��������������
		{
			if (ay == 0&&by == 0)    //���������Ϊ0�����˳�ѭ��
				break;
		}
		ay = 0;
		by = 0;
		 i = 1;             //��¼����ʮ����λ
		 j = 1;             //��¼����ʮ����λ
		while (ax / 10)                         //ѭ��ȡax�ĵ�һλʮ����λ
		{

			ay += ax % 10 * i;                  //��¼ȡ�����λ�������
			ax /= 10;
			i *= 10;
		}
		while (bx / 10)                         //ͬax
		{
			by += bx % 10 * j;
			bx /= 10;
			j *= 10;
		}
	
		
	} while (ax == bx);

	if (ax <= bx)                             //ע�⣡��׼������sort����ָ�����жϺ�������ж���������ȣ�����뷵��false
		return false;
	else
		return true;
}
string largestNumber(vector<int> &nums) {
	// write your code here
	//sort(nums.begin(), nums.end());
	sort(nums.begin(), nums.end(), cmp);            //�������������

	string str = "";
	for (auto n : nums)
	{
		if (!n&&str=="0")                   //�����ǰֻ��0
		{
			continue;
		}

		char a[11] = "";
		sprintf_s(a, "%d", n);             //C FREE using sprintf
		str.append(a);
	}
	return str;
}

int main()
{
	vector<int> as = { 9,90,9,99,92 };
	string str=largestNumber(as);
	if (str == "99999897979696959492929190908989888878785858585848181808080807876767574696766636361615757565555555453525150505049494743413938353533332313030282828282726262525242322222181716161614131313121111010")
		cout << "yes" << endl;
    return 0;
}

