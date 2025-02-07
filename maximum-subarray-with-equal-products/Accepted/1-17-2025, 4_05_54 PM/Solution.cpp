// https://leetcode.com/problems/maximum-subarray-with-equal-products

class Solution {
public:
    int maxLength(vector<int>& nums) { //1 <= nums[i] <= 10
        int n = nums.size();
        int ret = 0;
        for(int i=0; i<n; i++) {
            double prod = 1;
            long long gcds = nums[i];
            long long lcms = nums[i];
            for(int j=i; j<n; j++) {
                //if(prod>INT_MAX/nums[i]) //overflow
                //    break;
                prod *= nums[j];
                gcds = gcd(gcds, nums[j]);
                lcms = lcm(lcms, nums[j]);
                if(prod == lcms*gcds)
                    ret = max(ret, j-i+1);
            }
        }
        return ret;    
    }
};