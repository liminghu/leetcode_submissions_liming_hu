// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        /*  1 <= arr.length <= 10^5
            1 <= arr[i] <= 10^9
            0 <= k <= arr.length
        */
        int sz = arr.size();
        unordered_map<int, int> count; //num, count
        for(int i=0; i<sz; i++) {
            count[arr[i]]++;
        };
        //auto cmp = [](pair<int,int> a, pair<int,int> b) {
        //    return a.first < b.first;
        //};
        vector<int> frequencies;
        for(auto iter:count) 
           frequencies.push_back(iter.second);
        sort(frequencies.begin(), frequencies.end());


        int res = frequencies.size();
        for(int i=0; i<frequencies.size(); i++) {
            if(k >= frequencies[i]) {
                k -= frequencies[i];
                res--;
            } else 
                break;

        }

        return res;
    }
};