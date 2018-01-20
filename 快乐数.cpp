// 快乐数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
bool isHappy(int n) {
	// write your code here
	if (n == NULL)
		return 0;
	int count = 0;

	int p = n;
	int num=0;
	while (count < 100)
	{
		while (p/10|| p % 10)
		{
			num += (p % 10)*(p%10);
			p = p / 10;

		}
		if (num == 1)
			return true;
		else
		{
			p = num;
			num = 0;
		}
		count++;
	}
	return false;
	
}

int main()
{
	isHappy(19);
    return 0;
}

