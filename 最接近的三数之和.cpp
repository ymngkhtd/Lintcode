// 最接近的三数之和.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;




/*
* @param numbers: Give an array numbers of n integer
* @param target: An integer
* @return: return the sum of the three integers, the sum closest target.
*/
int threeSumClosest(vector<int> &numbers, int target) {
	// write your code here
	int nb = numbers.size();
	if (nb<3)                     //不够三个数，返回
		return 0;

	sort(numbers.begin(), numbers.end());                       //先从小到大排序
	int cha = INT_MAX;                    //用来记录最小差值
	int res = 0;                          //更新返回值
	for (int i = 0;i < nb;i++)         //遍历vector
	{                                  //i为第一个数序号
		int j = i + 1;                 //j为第二个数序号
		int k = nb - 1;                //k为第三个数序号
		
		while (j < k)                 //循环条件，j小于k
		{
			if (cha>abs(numbers[i] + numbers[j] + numbers[k] - target))        //如果本次循环三数和与target差值的绝对值比之前记录的最小差值要小(更接近target)
			{
				cha = abs(numbers[i] + numbers[j] + numbers[k] - target);      //更新差值
				res = numbers[i] + numbers[j] + numbers[k];                    //更新返回值
			}
			if (numbers[i] + numbers[j] + numbers[k] >target)                  //如果三数和大于target
			{
				--k;             
			}
			else if (numbers[i] + numbers[j] + numbers[k] < target)            //如果三数和小于target
			{
				++j;            
			}
			else
				return target;            //正好等于target，则返回
		}
	}
	return res;
}

int main()
{
	vector<int> te = { -2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5 };
	threeSumClosest(te, 45);
    return 0;
}

