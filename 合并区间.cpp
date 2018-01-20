// 合并区间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

class Interval{
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
//比较方法
static bool cmp(const Interval &a, const Interval &b)
{
	return a.start < b.start;
}


	/*
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	vector<Interval> merge(vector<Interval> &intervals) {
		// write your code here
		vector<Interval> vec;
		if (intervals.empty())
			return vec;
		sort(intervals.begin(), intervals.end(), cmp);  //将元素按照区间左界排序
		vec.push_back(intervals[0]);
		for (int i = 1;i < intervals.size(); i++)
		{
			if (vec.back().end >= intervals[i].start)
				vec.back().end = vec.back().end> intervals[i].end? vec.back().end: intervals[i].end;
			else
				vec.push_back(intervals[i]);
		}
		return vec;

	}




int main()
{
    return 0;
}

