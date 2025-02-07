// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       /* const int n = nums.size();
		vector<int> sums(n+1, 0);
		for(int i=1; i<=n; i++) 
			sums[i] = sums[i-1] + nums[i-1];
		int ans = 0;
		for(int i=0; i<n; i++)
			for(int j=i; j<n; j++)
				if(sums[j+1]-sums[i]==k) ans++;
			
		return ans;*/
        unordered_map<int, int> count_sums; //key: prefix sum, value: count of sums.
		count_sums[0] = 1;
		int sum =0;
		int result = 0;
		
		for(int i=0; i<nums.size(); i++) {
			sum += nums[i];
			
			if(count_sums.find(sum-k) != count_sums.end() ) {
				result += count_sums[sum-k];
			};
			
			if (count_sums.find(sum) != count_sums.end() ) {
				count_sums[sum]++;
			} else {
				count_sums[sum]=1;
			}
		}
		
		return result;
    }
};