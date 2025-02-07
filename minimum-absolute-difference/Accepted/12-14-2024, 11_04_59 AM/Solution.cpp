// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {//distinct integers arr
        sort(arr.begin(), arr.end());
        vector<vector<int>> rets;
        int abs_min = INT_MAX;
        for(int i=0; i<arr.size()-1; i++) {
            abs_min = min(abs_min, arr[i+1]-arr[i]);
        }
        for(int i=0; i<arr.size()-1; i++) {
            if (abs_min == arr[i+1]-arr[i])
                rets.push_back({arr[i], arr[i+1]});
        }
        //sort(rets.begin(), rets.end(), [](vector<int>& a, vector<int>& b) {return a[1]-a[0] < b[1]-b[0];});
        return rets;
    }
};