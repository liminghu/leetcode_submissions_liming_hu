// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {//1 <= values[i] <= 1000
        //i<j, values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
        int ans = values[0];
        int prevBestIdx = 0;
        for(int j=1; j<values.size(); j++) {
            ans = max(ans, values[prevBestIdx]+prevBestIdx+values[j]-j);
            if(values[prevBestIdx]+prevBestIdx < values[j]+j) {
                prevBestIdx = j;
            };
        };
        return ans;
    }
};