// 最多有多少个点在直线上.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include <unordered_map>
#include<algorithm>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
	// write your code here
	int nb = points.size();
	if (!nb)
		return 0;
	int maxp = 0;
	unordered_map <double, int> hama;   //内部由哈希表实现的无序map

	for (int i = 0;i < nb;i++)
	{
		hama.clear();
		int dup = 1;                //记录有多少点重复了

		for (int j = i + 1;j < nb;j++)
		{
			if (points[i].x == points[j].x && points[i].y == points[j].y)   //与下标为i的点重复的点
			{
				dup++;
				continue;
			}
			double slope = points[i].x == points[j].x ? INT_MAX : (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);   //记录斜率，如果两数横坐标相等，则为intmax
			hama[slope]++;                    //哈希表记录的该键值为slope的值加1
		}
		maxp = max(maxp, dup);         //最多有多少个点
		for (auto u : hama)          //遍历记录的斜率，和对应的个数；
		{
			if (maxp < u.second + dup)  
			maxp=u.second + dup;
		}
	}
	return maxp;
}

int main()
{
	vector<Point> ve;
	Point p(1, 2);
	Point p1(0, 0);
	Point p2(3, 6);
	Point p3(1, 3);
	Point p4(1, 5);
	ve.push_back(p);
	ve.push_back(p1);
	ve.push_back(p2);
	ve.push_back(p3);
	ve.push_back(p4);
	maxPoints(ve);
    return 0;
}

