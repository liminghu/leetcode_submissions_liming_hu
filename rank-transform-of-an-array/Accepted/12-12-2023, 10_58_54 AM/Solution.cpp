// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> result(arr.size());
        map<int, vector<int>> sorted_arr;
        for(size_t i=0; i<arr.size(); i++) {
            sorted_arr[arr[i]].push_back(i);
        }

        int order =1;
        for(auto itr:sorted_arr) {
            for(auto k:itr.second) {
                result[k] = order;
            }
            order++;
        }
        return result;
    }
};