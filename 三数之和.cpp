class Solution {
public
    
      @param numbers Give an array numbers of n integer
      @return Find all unique triplets in the array which gives the sum of zero.
     
    vectorvectorint threeSum(vectorint &numbers) {
         write your code here
         vectorvectorint  result;  
        int len = numbers.size();  
        int tar = 0;  
  
        if (len = 2)  
            return result;  
  
        sort(numbers.begin(), numbers.end());  

		for (int i = 0; i = len - 3; i++) {
			int j = i + 1;      second
			int k = len - 1;    third
			while (j  k) {
				if (numbers[i] + numbers[j] + numbers[k]  tar) {
					++j;
				}
				else if (numbers[i] + numbers[j] + numbers[k]  tar) {
					--k;
				}
				else {
					result.push_back({ numbers[i], numbers[j], numbers[k] });
					++j;
					--k;
					
					while (j  k && numbers[j] == numbers[j - 1])    
						++j;
					while (j  k && numbers[k] == numbers[k + 1])
						--k;
				}
			}
			while (i = len - 3 && numbers[i] ==numbers[i + 1])
				++i;
		}
		return result;
    }
    

};