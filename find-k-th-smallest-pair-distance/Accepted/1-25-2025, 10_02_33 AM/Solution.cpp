// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = nums[n-1]-nums[0];
        while(l<h) {
            int mid = (l+h)/2;
            int count = countPairWithMaxDistance(nums, mid);
            if(count<k)
                l = mid+1;
            else
                h = mid;
        }
        return l;
    }
    int countPairWithMaxDistance(vector<int>&  nums, int maxDist) {
        int count = 0;
        int n = nums.size();
        int l = 0;
        for(int r = 0; r<n; r++) {
            while(nums[r]-nums[l]>maxDist)
                l++;
            count += r-l;
        }
        return count;
    }
};