// x��n����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;

double power(double x, int n) {
	if (n == 1)                  //�ݹ鵽nΪ1
		return x;
	double mid = power(x, n / 2);  //���η�������x��n/2����

	if (n & 1)                //nΪ����
	{
		return mid*mid*x;     //��Ҫ�ٳ�x
	}
	else
		return mid*mid;
}

double myPow(double x, int n) {
	// write your code here
	if (!x&&n < 0)                //xΪ0����n<0����������õݹ鷽�����Ϊ������Ƚ��д���
		return 0;
	if (!n)                      //nΪ0
		return 1;
	if (n == INT_MIN)                //��ֹ��ջ
		return 0;
	if (n > 0)                  
		return power(x, n);
	else
		return (1 / power(x, -n));               //nΪ���������ȡ����
	
}
int main()
{
	int a = INT_MIN+10;
	int b=myPow(2.00000, 3);
    return 0;
}

