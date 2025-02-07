// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

class Solution {
public:
    int minimumPushes(string word) {
        //calculate frequency
        vector<int> f(26);
        for(auto &w:word)
            f[w-'a']++;
        sort(f.rbegin(), f.rend());  //sort in descending order
        vector<int> position(8,8);
        int ans = 0;

        for(int i=0, j=0; i<26; i++) {
            if(f[i]) {
                ans += f[i]*(j+1); //max frequency, min position
                if(--position[j] == 0) { // if jth position is not available then go for next position at place 8 letters
                     j++;
                }
            }
        }
        return ans;
    }
};