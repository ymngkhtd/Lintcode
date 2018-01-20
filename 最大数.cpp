// 最大数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>	
#include<vector>
#include<algorithm>
using namespace std;

// bool reten(int &a,int &b)
//递归的方法，爆栈
//{
//	
	//bool biger = true;     //返回值，ture为a在b前，false则相反
	//int ax = a;
	//int bx = b;
	//int ay = 0;            //用来保存a余数
	//int by = 0;            //保存b余数
	//int i = 1;             //记录余数十进制位
	//int j = 1;             //记录与数十进制位
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
//	if (ax == bx)                 //如果a的首位与b的首位相等
//		biger = reten(ay, by);       //将余数作为参数进行判断
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
//排序原则
{
	if (!a)
		return false;
	if (!b)
		return true;

	if (a == b)
		return false;
	int ax = a;            //保存每次循环判断的a的十进制最高位
	int bx = b;            //保存每次循环判断的b的十进制最高位
	int ay = 0;            //用来保存a余数
	int by = 0;            //保存b余数
	int i = 1;
	int j = 1;
	do
	{
		if (!(ax==a&&bx==b))         //非首次循环
		{
			if(i!=1)                 //如果a有不止一位十进制位
			ax = ay;                 //本次循环对上次循环的余数进行操作
			if(j!=1)                 //如果只有一位十进制位，则本次仍操作上一次循环的数
			bx = by;
		}
		 if(ax==bx)                  //如果操作的数相等
		{
			if (ay == 0&&by == 0)    //如果余数都为0，则退出循环
				break;
		}
		ay = 0;
		by = 0;
		 i = 1;             //记录余数十进制位
		 j = 1;             //记录余数十进制位
		while (ax / 10)                         //循环取ax的第一位十进制位
		{

			ay += ax % 10 * i;                  //记录取完最高位后的余数
			ax /= 10;
			i *= 10;
		}
		while (bx / 10)                         //同ax
		{
			by += bx % 10 * j;
			bx /= 10;
			j *= 10;
		}
	
		
	} while (ax == bx);

	if (ax <= bx)                             //注意！标准决定：sort（）指定的判断函数如果判断两参数相等，则必须返回false
		return false;
	else
		return true;
}
string largestNumber(vector<int> &nums) {
	// write your code here
	//sort(nums.begin(), nums.end());
	sort(nums.begin(), nums.end(), cmp);            //对数组进行排序

	string str = "";
	for (auto n : nums)
	{
		if (!n&&str=="0")                   //如果当前只有0
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

