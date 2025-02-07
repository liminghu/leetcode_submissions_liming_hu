// https://leetcode.com/problems/cutting-ribbons

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {//1 <= k <= 109
    //Your task is to determine the maximum length of ribbon, x, 
    //that allows you to cut at least k ribbons, each of length x. 
    //You can discard any leftover ribbon from the cuts. If it is 
    //impossible to cut k ribbons of the same length, return 0.
        int ret = 0;
        int n = ribbons.size();
        long long  sum = 0;
        int left = 0;
        int right = 1;
        for(auto ribbon:ribbons) {
            sum += ribbon;
            right = max(right, ribbon);
        }
        if(k>sum)
            return 0;
        sort(ribbons.begin(), ribbons.end());
        while(left<right) {
            int mid = left+(right-left+1)/2; //prevent dead loop
            bool tf = isPossible(ribbons, k, mid);
            if(tf)
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    bool isPossible(vector<int>& ribbons, int k, int x) {
        int totalRibbons = 0;
        for(int ribbon:ribbons) {
            int pieces = ribbon/x;
            totalRibbons += pieces;
            if(totalRibbons>=k)
                return true;
        }
        return false;
    }
};