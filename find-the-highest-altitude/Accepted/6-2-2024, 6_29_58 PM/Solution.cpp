// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
//You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). 
//Return the highest altitude of a point.
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cur_sum = ans;
        int n = gain.size();
        for(int i=0; i<n; i++) {
            cur_sum += gain[i];
            if(cur_sum > ans) 
                ans = cur_sum;
        }
        return ans;
    }
};