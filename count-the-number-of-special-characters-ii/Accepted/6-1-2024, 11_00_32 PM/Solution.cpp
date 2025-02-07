// https://leetcode.com/problems/count-the-number-of-special-characters-ii

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> dict_lower(26,-1);
        vector<int> dict_upper(26,-1);
        for(int i=0; i<word.length(); i++) {
            if(word[i]>='a' & word[i]<='z') 
                dict_lower[word[i]-'a']=i; //record the last location.
            else {
                if(dict_upper[word[i]-'A']==-1)
                    dict_upper[word[i]-'A'] = i;
            }
        };

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(dict_lower[i]>=0 & dict_upper[i]>=0 & dict_lower[i] < dict_upper[i])
                ans++;
        };

        return ans; 
    }
};