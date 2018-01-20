// 罗马数字转整数.cpp : 定义控制台应用程序的入口点。
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
	int res = chartoint(s[size - 1]);               //res先赋为最后一个元素
	for (int i = size - 2;i >= 0;i--) {             //从倒数第二个元素开始向前循环
		if (chartoint(s[i]) < chartoint(s[i + 1]))       //如果它后面的元素比他大，则res减去它
			res -= chartoint(s[i]);
		else                                          //否则加上它（对应的数值）
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

