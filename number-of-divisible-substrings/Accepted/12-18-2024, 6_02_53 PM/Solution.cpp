// https://leetcode.com/problems/number-of-divisible-substrings

class Solution {
int map[26] = {1, 1,  2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9};
public:
    int countDivisibleSubstrings(string word) {
       //A string is divisible if the sum of the mapped values of its characters is divisible by its length
        int n = word.length();
        int ret = 0;
        for(int i=1; i<10; i++) { //Try all the possible average value a from 1 to 9.
            unordered_map<int,int> have;
            have[0] = 1;
            int sum = 0;
            for(char c: word) {
                sum += map[c-'a'] - i;
                ret += have[sum];
                have[sum]++;
            } 
        }
        return ret;
    }

};