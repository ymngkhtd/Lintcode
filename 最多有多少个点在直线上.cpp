// ����ж��ٸ�����ֱ����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	unordered_map <double, int> hama;   //�ڲ��ɹ�ϣ��ʵ�ֵ�����map

	for (int i = 0;i < nb;i++)
	{
		hama.clear();
		int dup = 1;                //��¼�ж��ٵ��ظ���

		for (int j = i + 1;j < nb;j++)
		{
			if (points[i].x == points[j].x && points[i].y == points[j].y)   //���±�Ϊi�ĵ��ظ��ĵ�
			{
				dup++;
				continue;
			}
			double slope = points[i].x == points[j].x ? INT_MAX : (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);   //��¼б�ʣ����������������ȣ���Ϊintmax
			hama[slope]++;                    //��ϣ���¼�ĸü�ֵΪslope��ֵ��1
		}
		maxp = max(maxp, dup);         //����ж��ٸ���
		for (auto u : hama)          //������¼��б�ʣ��Ͷ�Ӧ�ĸ�����
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

