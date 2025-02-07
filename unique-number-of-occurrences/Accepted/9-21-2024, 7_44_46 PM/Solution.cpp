// https://leetcode.com/problems/unique-number-of-occurrences

/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) {
             mp[arr[i]]++;
        }
        unordered_map<int,int> mp2;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i])!=mp.end()) {
                int occurance = mp[arr[i]];
                mp.erase(arr[i]);
                if(mp2.find(occurance)== mp2.end())
                    mp2[occurance] = arr[i];
                else
                    return false;
            }
        }
        return true;

    }
};