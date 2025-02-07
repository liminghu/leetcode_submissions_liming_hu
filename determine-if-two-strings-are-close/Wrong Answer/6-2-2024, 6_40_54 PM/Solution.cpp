// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {//word1 and word2 contain only lowercase English letters.
        bool ans = false;
        vector<int> dict1(26,0);
         vector<int> dict2(26,0);
        int n1 = word1.length();
        int n2 = word2.length();
        if(n1!=n2)
            return false;
        
        for(int i=0; i<n1; i++) {
            dict1[word1[i]-'a']++;
            dict2[word2[i]-'a']++;
        }
        sort(dict1.begin(), dict1.end());
        sort(dict2.begin(), dict2.end());
        for(int i=0; i<26; i++) {
            if(dict1[i]!=dict2[i])
                return false;
        }
        return true;
    }
};