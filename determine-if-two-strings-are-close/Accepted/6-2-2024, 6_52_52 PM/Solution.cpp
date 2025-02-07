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

        //int sum_f1=0;
        //int sum_f2=0;
        for(int i=0; i<26; i++) {
            if((dict1[i]==0 && dict2[i]!=0) || (dict1[i]!=0 && dict2[i]==0))
                return false;
           // sum_f1 += dict1[i];
           // sum_f2 += dict1[i];
        }
        sort(dict1.begin(), dict1.end());
        sort(dict2.begin(), dict2.end());
        if(dict1== dict2)
            return true;
        else 
            return false;
    }
};