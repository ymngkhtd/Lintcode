#include<iostream>
#include<vector>

using namespace std;

int longestCommonSubsequence(string &A, string &B) {
	// write your code here
	if (A.empty() || B.empty())
		return 0;
	int n = A.length();
	int m = B.length();
	int lcsn = 0;                 //记录最长公共子序列
	vector<vector<int>> cs(n+1);
	for (int a = 0;a < n+1;a++)
	{
		cs[a].resize(m+1);        //初始化
		if (a == 0)                    
			continue;
		for (int b = 1;b < m + 1;b++)
		{
			if (A[a - 1] == B[b - 1])              //如果两字符相同
				cs[a][b] = cs[a - 1][b - 1] + 1;       //那么lcs长度为减去该字符后lcs长度+1
			else 
			{
				cs[a][b] = cs[a - 1][b]>cs[a][b - 1] ? cs[a - 1][b] : cs[a][b - 1];       //否则lcs长度为A减去一字符与B的lcs、B减去一个字符与A的lcs两者的最大值
			}
			lcsn = lcsn > cs[a][b] ? lcsn : cs[a][b];        //更新最长纪录
		}
	}
	return lcsn;


}

int main()
{
	string s1 = "ABREDSGF";
	string s2 = "VDREWASF";
	longestCommonSubsequence(s1,s2);
	return 0;
}