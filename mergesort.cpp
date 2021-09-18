// mergesort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <vector>

#define Buffer_Size 99999


auto Sorted = [](std::vector<int>& a)->bool
{int nLast = INT_MIN;
for (auto itm : a)
{
	if (itm < nLast)
		return false;
	nLast = itm;
}
return true; };

auto ScreenTimeNow = []()
{
	time_t timeS;
	char cTBuf[128] = { 0 };
	time(&timeS); /*获取time_t类型的当前时间*/
	ctime_s(cTBuf, 128, &timeS);
	std::cout << cTBuf << std::endl;
};
void merge(std::vector<int>& a, std::vector<int>& aux, int lo, int mid, int high)
{
	//先将需要的数据复制到缓存数组中
//     for (auto& itm : a)
//     {
//         aux.push_back(itm);
//     }
	//vector空间连续，可以直接拷贝
	memcpy(&aux[lo], &a.at(lo), sizeof(int)*(high - lo + 1));

// 	for (int nidx = lo; nidx <= high; ++nidx)
// 	{
// 		aux[nidx] = a.at(nidx);
// 	}
	//两个索引，分别对应起始和中间位置
	int ni = lo, nj = mid + 1;
	//遍历决定a数组中lo到high每个元素按序应该是什么
	for (int nk = lo; nk <= high; ++nk)
	{

		//如果前面的有序数组遍历完，则将后面有序数组元素直接填充到a的nk之后的位置
		if (ni > mid)
		{
// 			a[nk] = aux.at(nj);
// 			++nj;
			memcpy(&a[nk], &aux.at(nj), sizeof(int)*(high - nk + 1));
			break;
		}
		//同理，如果后边的....
		else if (nj > high)
		{
//  			a[nk] = aux.at(ni);
//  			++ni;
			memcpy(&a[nk], &aux.at(ni), sizeof(int)*(high - nk + 1));
			break;
		}
		//前面的有序数组的第ni个位置元素和后面的有序数组第nj个位置元素 大小判断
		//a的第nk个位置存放更小的那个元素
		else if (aux.at(ni) < aux.at(nj))
		{
			a[nk] = aux.at(ni);
			++ni;
		}
		else
		{
			a[nk] = aux.at(nj);
			++nj;
		}

	}


}
void sort(std::vector<int>& a, std::vector<int>& aux, int lo, int high)
{
	if (lo >= high)
		return;
	auto mid = lo + (high - lo) / 2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid + 1, high);
	//两部分已经是排好序，左边最大小于右边最小，不用merge的了
	if (a.at(mid) <= a.at(mid + 1))
		return;
	merge(a, aux, lo, mid, high);
}
int main()
{
	std::vector<int> testvec;
	std::vector<int> vecmid;

	std::ifstream infile;
	char cBuf[Buffer_Size] = { '\0' };
	infile.open("F:\\algorithms\\lintcode\\mergesort\\Debug\\testfile.txt");
	infile >> cBuf;

	char* pLast = cBuf;
	for (char* pchar = cBuf; *pchar != '\0'; ++pchar)
	{
		if (*pchar == ',')
		{
			char pBufmid[128] = { 0 };
			memcpy(pBufmid, pLast, pchar - pLast);
			pLast = pchar + 1;

			testvec.push_back(atoi(pBufmid));

		}
	}
	ScreenTimeNow();
	for (auto itm : testvec)
	{
		vecmid.push_back(itm);
	}
	sort(testvec, vecmid, 0, testvec.size() - 1);
	ScreenTimeNow();

	if (Sorted(testvec))
		std::cout << "Sorted!\n";
	else
		std::cout << "Sort faild!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
