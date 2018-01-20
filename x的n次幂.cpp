// x的n次幂.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

double power(double x, int n) {
	if (n == 1)                  //递归到n为1
		return x;
	double mid = power(x, n / 2);  //分治法，计算x的n/2次幂

	if (n & 1)                //n为奇数
	{
		return mid*mid*x;     //需要再乘x
	}
	else
		return mid*mid;
}

double myPow(double x, int n) {
	// write your code here
	if (!x&&n < 0)                //x为0并且n<0，这种情况用递归方法算出为无穷大，先进行处理
		return 0;
	if (!n)                      //n为0
		return 1;
	if (n == INT_MIN)                //防止爆栈
		return 0;
	if (n > 0)                  
		return power(x, n);
	else
		return (1 / power(x, -n));               //n为负，计算后取倒数
	
}
int main()
{
	int a = INT_MIN+10;
	int b=myPow(2.00000, 3);
    return 0;
}

