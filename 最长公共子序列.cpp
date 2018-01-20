#include<iostream>
#include<vector>

using namespace std;

int longestCommonSubsequence(string &A, string &B) {
	// write your code here
	if (A.empty() || B.empty())
		return 0;
	int n = A.length();
	int m = B.length();
	int lcsn = 0;                 //��¼�����������
	vector<vector<int>> cs(n+1);
	for (int a = 0;a < n+1;a++)
	{
		cs[a].resize(m+1);        //��ʼ��
		if (a == 0)                    
			continue;
		for (int b = 1;b < m + 1;b++)
		{
			if (A[a - 1] == B[b - 1])              //������ַ���ͬ
				cs[a][b] = cs[a - 1][b - 1] + 1;       //��ôlcs����Ϊ��ȥ���ַ���lcs����+1
			else 
			{
				cs[a][b] = cs[a - 1][b]>cs[a][b - 1] ? cs[a - 1][b] : cs[a][b - 1];       //����lcs����ΪA��ȥһ�ַ���B��lcs��B��ȥһ���ַ���A��lcs���ߵ����ֵ
			}
			lcsn = lcsn > cs[a][b] ? lcsn : cs[a][b];        //�������¼
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