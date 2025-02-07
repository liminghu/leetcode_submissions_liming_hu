// https://leetcode.com/problems/continuous-subarray-sum

/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:
A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*  1 <= nums.length <= 105
            0 <= nums[i] <= 109
            0 <= sum(nums[i]) <= 231 - 1
            1 <= k <= 231 - 1
        */
        vector<int> prefixSum(nums.size()+1, 0);
        unordered_map<int, int> mp;
        
        prefixSum[0] = 0;
        mp[ 0 % k ] = 1;
        
        prefixSum[1] = nums[0] % k;
        mp[ nums[0] % k ] = 1;
        //cout << nums[0] % k << endl;
        //cout << prefixSum[1] << endl;
        //cout << 0 <<  " prefixSum[i+1]%k= " << prefixSum[0+1] << endl;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]%k==0 && nums[i-1]%k==0)
                return true;
            if(nums[i] != 0 ) {
                prefixSum[i+1] = ( prefixSum[i] + nums[i] ) % k;
                cout << i<<  " prefixSum[i+1]%k= " << prefixSum[i+1] << endl;
                if( mp.find(prefixSum[i+1]) != mp.end() )
                    return true;
                else
                    mp[prefixSum[i+1]] = 1;
            } else {
                prefixSum[i+1] = prefixSum[i];
            }
        };
        return false;
    }
};