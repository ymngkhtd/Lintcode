// �˻����������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int res = nums[0];                  //����ֵ
	int zmax = nums[0];                //��¼�����
	int fmax = nums[0];                //��¼����С
	for (int i = 1;i < n;i++)
	{
		int zmaxmid = zmax;
		int fmaxmid = fmax;
		zmax = max(nums[i], max(zmaxmid*nums[i], fmaxmid*nums[i]));         //��Ԫ��i��Ϊ������β����������г˻�Ϊ��i���� �루��iǰһԪ����Ϊ������β����������г˻����ٳ���i �� ��iǰһԪ����Ϊ������β����С�����г˻����ٳ���i ֮��Ľϴ�ֵ��֮��Ľϴ�ֵ
		fmax = min(nums[i], min(zmaxmid*nums[i], fmaxmid*nums[i]));
		res = max(res, zmax);
	}
	return res;
}

int main()
{
    return 0;
}

