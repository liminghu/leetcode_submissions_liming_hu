// https://leetcode.com/problems/split-array-with-equal-sum

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        //triplet (i, j, k)
        //0 < i, i + 1 < j, j + 1 < k < n - 1
        //The sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) is equal.
        int n = nums.size();
        if(n<7)
            return false;
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for(int i=1; i<n; i++)
            sum[i] = nums[i] + sum[i-1];
        for(int j=3; j<n-3; j++) {
            unordered_set<int> st;
            for(int i=1; i<j-1; i++) {
                if(sum[i-1]==sum[j-1]-sum[i])
                    st.insert(sum[i-1]);
            }
            for(int k=j+2; k<n-1; k++) {
                if(sum[n-1]-sum[k] == sum[k-1]-sum[j] && st.find(sum[k-1]-sum[j])!=st.end())
                    return true;
            }
        } 
        return false;
    }
};