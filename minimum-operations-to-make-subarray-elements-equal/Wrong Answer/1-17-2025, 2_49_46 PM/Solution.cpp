// https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal

class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        //Return the minimum number of operations required to ensure that at least one subarray of size k in nums has all elements equal.
        int n = nums.size();
        multiset<int> below_median; //multiset for sorted duplicates
        multiset<int> above_median;
        long long below_sum = 0;
        long long above_sum = 0;
        for(int i=0; i<k-1; i++) {
            below_median.insert(nums[i]);
            below_sum += nums[i];
        }
        int median_idx = k/2;
        bool odd = (k%2==1);
        long long min_cost = LLONG_MAX;
        for(int l = 0; l<=n-k; l++) {
            int r = l+k-1;
            int r_num = nums[r];
            below_median.insert(r_num);
            below_sum += r_num;
            while(below_median.size()>median_idx) {
                auto it = prev(below_median.end());
                int r_of_below = *it;
                below_sum -= r_of_below;
                below_median.erase(it);
                above_median.insert(r_of_below);
                above_sum += r_of_below;
            }
            long long local_cost = above_sum - below_sum;
            if(odd)
                local_cost -= *above_median.begin();
            min_cost = min(min_cost, local_cost);
            int removal_val = nums[l];
            if(below_median.find(removal_val)!=below_median.end()) {
                below_median.erase(below_median.find(removal_val));
                below_sum -= removal_val;
            } else {
                above_median.erase(above_median.find(removal_val));
                above_sum -= removal_val;                
            }
        }
        return min_cost;

    }
};