// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;	

int backPack(int m, vector<int> A) {
	// write your code here
	
	vector<int> kj(m+1);             //������������͸��£�������Ϊmʱ������װ��A����Ʒ�������
	int n = A.size();
	for (int i = 0;i < n;i++)        //��ѭ������A�е���Ʒ
	{
		for (int j = m;j > 0;j--)    //��ѭ����m��ʼ��С
		{
			if(j>=A[i])             //�������j����װ��A�е������Ʒ��A[i]��
			kj[j] = max(kj[j], kj[j - A[i]] + A[i]);         //����kj��������Ϊjʱ��������װ�£�
			                                                 //1.ǰi-1��ѭ�������������Ϊjʱ����װ�µ���Ʒ���������
			                                                 //2.����װ��A�е������Ʒ��ǰi-1��ѭ���������ʣ��Ŀռ仹��װ�µ���Ʒ�������������A�е������Ʒ�������
			                                                 //ȡ1��2�Ľϴ�ֵ��
		}
			
	}
	return kj[m];
}
int main()
{
	vector<int> a = { 3,4,8,5 };
	backPack(10, a);
    return 0;
}

