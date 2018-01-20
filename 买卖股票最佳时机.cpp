#include<vector>
using namespace std;
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(vector<int> &prices) 
	{
		// write your code here  
		if (prices.size() == 0) 
			return 0;


		int max = 0;
		int chance = prices[0];     //可能获得更大利润的买进价
		for (int i = 0; i < prices.size(); ++i) 
		{
			if (prices[i] < chance) 
				chance = prices[i];       

			else 
				max = prices[i] - chance>max ? prices[i] - chance : max;

		}
		return max;
	}