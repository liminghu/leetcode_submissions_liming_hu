// https://leetcode.com/problems/sort-the-people

/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.
 */
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> hm;
        for(int i=0; i<names.size(); i++) 
            hm[heights[i]] = names[i];
        
        sort( heights.begin(), heights.end(), [](int i, int j) { 
            return i > j;
            });
        vector<string> res;
        for(int i=0; i<heights.size(); i++) {
            res.push_back(hm[heights[i]]);
        }
        return res;
    }
};