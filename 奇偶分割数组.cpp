#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	/*
	* @param nums: an array of integers
	* @return: nothing
	*/
	void partitionArray(vector<int> &nums) {
		// write your code here
		if (nums.begin() == nums.end())
			return;
		int nb;
		std::vector<int>::iterator it1 = nums.begin();
		std::vector<int>::iterator it2 = nums.end();
		it2--;
		
		while (it1 <= it2)
		{
			
		
		while (*it1 & 1)            //find first even number
		{

			it1++;
		}

		while (!(*it2 & 1))            //find first odd number
		{

			it2--;
		}
		if (it1 <= it2)
		{
			int mid = *it1;
			*it1 = *it2;
			*it2 = mid;
		}
		

		}
		vector<int> vec = nums;
		cin >> nb;
	}

	
};

	int main()
	{
		vector<int> vec = {1,2,14,56,789,2,46};
		Solution s;
		s.partitionArray(vec);
		return 0;

	}