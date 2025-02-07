// https://leetcode.com/problems/k-th-smallest-prime-fraction

/*
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. 
You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, 
where answer[0] == arr[i] and answer[1] == arr[j].
*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        /*  2 <= arr.length <= 1000
            1 <= arr[i] <= 3 * 104
            arr[0] == 1
            arr[i] is a prime number for i > 0.
            All the numbers of arr are unique and sorted in strictly increasing order.
            1 <= k <= arr.length * (arr.length - 1) / 2
        */
        //arr[i] / arr[j]
        double left = 0;
        double right = 1;
        double mid;
        while( left < right ) {
            mid = (left+right)/2;
            int count = 0; //number of nums[i]/nums[j] <= mid.
            for(int i=0; i<nums.size(); i++) {
                auto pos = lower_bound(nums.begin(), nums.end(), nums[i]*1.0/mid);    //nums[i]/nums[j] <=mid -> nums[j] >=nums[i]*mid;
                count += nums.end() - pos; //nums[j] .....    greater.
            }
            if(count < k)
                left = mid; 
            else if(count > k )
                right = mid;
            else
                break;
        }

        vector<int> ret;
        double ans = 0;
        for(int i=0; i<nums.size(); i++) {
            auto pos = lower_bound(nums.begin(), nums.end(), nums[i]*1.0/mid);    //nums[i]/nums[j] <=mid -> nums[j] >=nums[i]*mid;
            int j = pos - nums.begin();
            if( pos != nums.end() && nums[i]*1.0/nums[j] > ans) {
                ans = nums[i]*1.0/nums[j];
                ret = {nums[i], nums[j]};
            }
        }
        return ret;
    }
};