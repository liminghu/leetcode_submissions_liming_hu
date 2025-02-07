// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        istringstream iss(s);
        int count = 0;
        string word;
        while(iss>>word)
            count++;
        return count;
    }
};