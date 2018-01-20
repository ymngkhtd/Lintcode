// 乘积最大子序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	if (!n)
		return 0;
	int res = nums[0];                  //返回值
	int zmax = nums[0];                //记录正最大
	int fmax = nums[0];                //记录负最小
	for (int i = 1;i < n;i++)
	{
		int zmaxmid = zmax;
		int fmaxmid = fmax;
		zmax = max(nums[i], max(zmaxmid*nums[i], fmaxmid*nums[i]));         //以元素i作为子序列尾的最大子序列乘积为：i本身 与（以i前一元素作为子序列尾的最大子序列乘积，再乘以i 与 以i前一元素作为子序列尾的最小子序列乘积，再乘以i 之间的较大值）之间的较大值
		fmax = min(nums[i], min(zmaxmid*nums[i], fmaxmid*nums[i]));
		res = max(res, zmax);
	}
	return res;
}

int main()
{
    return 0;
}

