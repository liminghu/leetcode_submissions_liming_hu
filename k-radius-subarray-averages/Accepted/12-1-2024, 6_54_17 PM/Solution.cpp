// https://leetcode.com/problems/k-radius-subarray-averages

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avg(n, -1);
        long long sum = 0;
        for(int i=0; i<n && i<=2*k; i++) {
           sum += nums[i]; 
        }
        cout << sum << endl;
        for(int i=k; i+k<n; i++) {
            //cout << sum << endl;
            avg[i] = floor(sum*1.0/(2*k+1.0) );
            if(i+k+1<n)
                sum += (nums[i+k+1] - nums[i-k]);
        };
        return avg;
    }
};