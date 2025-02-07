// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {//Given a string s consisting only of characters a, b and c.
        //Return the number of substrings containing at least one occurrence of all these characters a, b and c.
        int n = s.length();
        if(n<3)
            return 0;
        int count[3] = {0, 0, 0};
        int ret = 0;
        int i=0; 
        for(int j=0; j<n; j++) {
            count[s[j]-'a']++;
            while(count[0] && count[1] && count[2]) {
                count[s[i]-'a']--;
                i++;
            };
            ret += i;
        }
        return ret;
    }
};