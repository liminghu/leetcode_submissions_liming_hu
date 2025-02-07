// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int, int> sweep;
        for(size_t i=0; i<ranges.size(); i++) {
            sweep[ranges[i][0]]++;
            sweep[ranges[i][1]+1]--;
        }
        if(sweep.begin()->first > left || sweep.rbegin()->first < right)
            return false;
        int result = 0;
        for(auto itr: sweep) {
            result +=itr.second;
            if(result == 0 && itr.first >=left && itr.first <= right)
            return false;
        }
        return true;
    }
};