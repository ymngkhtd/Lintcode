// ��������ת����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<map>
using namespace std;

int chartoint(char a)
{
	switch (a)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;


	default:
		return 0;
	}
}
int romanToInt(string &s) {
	// write your code here
	int size = s.size();
	if (!size)
		return 0;
	int res = chartoint(s[size - 1]);               //res�ȸ�Ϊ���һ��Ԫ��
	for (int i = size - 2;i >= 0;i--) {             //�ӵ����ڶ���Ԫ�ؿ�ʼ��ǰѭ��
		if (chartoint(s[i]) < chartoint(s[i + 1]))       //����������Ԫ�ر�������res��ȥ��
			res -= chartoint(s[i]);
		else                                          //�������������Ӧ����ֵ��
			res += chartoint(s[i]);
	}
	return res;

}

int main()
{
	string str = { "MMMCMXCIX" };
	int a = romanToInt(str);
    return 0;
}

