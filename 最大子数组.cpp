// ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

int maxSubArray(vector<int> &nums) {
	// write your code here
	int nowc = 0;
	int res = INT_MIN;
	for (auto n : nums)
	{
		nowc = nowc + n;
		res = max(res, nowc);
		if (nowc<0)                  //�����������Ϊ��������
			nowc = 0;
	}
	return res;
}
int main()
{
	vector<int> num1 = { -2,1 };
	maxSubArray(num1);
    return 0;
}

