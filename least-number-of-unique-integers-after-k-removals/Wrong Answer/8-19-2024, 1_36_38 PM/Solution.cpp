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
        map<int,int> mp;
        for(auto iter:count) {
            mp.insert({iter.first, iter.second,});
        };

        int i=0;
        int res = mp.size();
        auto iter = mp.begin();
        while(iter != mp.end()) {
            if(k>=iter->second) {
                cout <<"count: "<< iter->second << " num = " << iter->first << endl; 
                k = k -iter->second;
                iter = next(iter);
                res--;
            } else 
                break;
        }

        if (k>0)
            res--;
        return res;        
    }
};