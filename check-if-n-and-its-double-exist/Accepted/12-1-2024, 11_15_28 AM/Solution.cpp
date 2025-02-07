// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, unordered_set<int>> dict;
        for(int i=0; i<arr.size(); i++)
            dict[ arr[i] ].insert(i);
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) {
                if(dict[arr[i]].size()>1)
                    return true;
            } else {
                if( dict.find( 2*arr[i] ) != dict.end() )
                    return true;
                if(arr[i] % 2 == 0) {
                    if( dict.find( arr[i]/2 ) != dict.end() )
                    return true;
                } 
            }
        }
        return false;
    }
};