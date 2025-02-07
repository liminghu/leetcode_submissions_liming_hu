// https://leetcode.com/problems/kth-distinct-string-in-an-array

/*A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct 
string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.
*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;

        // First pass: Populate the frequency map
        for (string& str : arr) {
            frequencyMap[str]++;
        }

        // Second pass: Find the k-th distinct string
        for (string& str : arr) {
            // Check if the current string is distinct
            if (frequencyMap[str] == 1) {
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
 
 /*       int sz = arr.size();
        unordered_map<string, int> mp;  //string, idx
        vector<int> idx(sz, -1); //idx, string
        
        int count = 0;
        for(int i=0; i<sz; i++) {
            if( mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
                idx[i] = i;
                count++;
            } else {
                //delete arr[i];
                idx[mp[arr[i]]] = -1;
                mp.erase(arr[i]);
                count--;
            }
        }
        if(count < k)
            return "";

        count = 0;
        for(int i=0; i<sz; i++) {
            if(idx[i] != -1)
                count++;

            if(count == k )
                return arr[i];
        }

        return "";*/
        
    }
};