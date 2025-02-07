// https://leetcode.com/problems/brightest-position-on-street

class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> street;
        for(size_t i=0; i<lights.size(); i++) {
            int left = lights[i][0] - lights[i][1];
            int right = lights[i][0] + lights[i][1] + 1;
            street[left]++;
            street[right]--;
        }
        
        int result = street.begin()->first;
        int prev = street.begin()->second;
        int sum = 0;
        for(auto& itr:street) {
            sum += itr.second;
            if(sum>prev) {
                result = itr.first;
                prev = sum;
            }
        }
        return result;

    }
};