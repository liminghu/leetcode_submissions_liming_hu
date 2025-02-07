// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) { //s consists of lowercase English letters.
        vector<int> charCounts(26,0);
        for(char c:s) {
            charCounts[c-'a']++;
        };

         int maxCount = 0;
         int letter = 0;
         for(int i=0; i<charCounts.size(); i++) { //get the maximum frequency, and the related letter.
            if(charCounts[i]>maxCount) {
                maxCount = charCounts[i];
                letter = i;
            }
         }

         if(maxCount >(s.length()+1)/2) 
            return "";
        
        string ans = s;
        int index = 0;
        //place the most frequent letter
        while(charCounts[letter]!=0) {
            ans[index] = char(letter+'a');
            index+=2;
            charCounts[letter]--;
        };

        for(int i=0; i<charCounts.size(); i++) {
            while(charCounts[i] >0) {
                if(index>=s.length())
                    index = 1;
                ans[index]= char(i+'a');
                index+=2;
                charCounts[i]--;
            }
        }

        return ans;
    }
};