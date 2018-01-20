// 背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;	

int backPack(int m, vector<int> A) {
	// write your code here
	
	vector<int> kj(m+1);             //容器用来保存和更新：当容量为m时，可以装下A中物品的最大量
	int n = A.size();
	for (int i = 0;i < n;i++)        //外循环遍历A中的物品
	{
		for (int j = m;j > 0;j--)    //内循环从m开始减小
		{
			if(j>=A[i])             //如果容量j可以装下A中的这个物品（A[i]）
			kj[j] = max(kj[j], kj[j - A[i]] + A[i]);         //更新kj，当容量为j时，最多可以装下：
			                                                 //1.前i-1次循环计算出的容量为j时最多可装下的物品的最大量；
			                                                 //2.假设装下A中的这个物品后，前i-1次循环计算出的剩余的空间还可装下的物品的最大量。加上A中的这个物品的体积。
			                                                 //取1和2的较大值。
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

