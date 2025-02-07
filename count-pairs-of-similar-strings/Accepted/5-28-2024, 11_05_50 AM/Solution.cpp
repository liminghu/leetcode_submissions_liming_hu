// https://leetcode.com/problems/count-pairs-of-similar-strings

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;

        if (words.size() <=1)
            return 0;

        for(int i=0; i<words.size()-1; i++) {

            int dict_i[26]; //words[i] consist of only lowercase English letters.
            for(int k=0; k<words[i].length(); k++) 
                dict_i[words[i][k]-'a']++;

            for(int j=i+1; j<words.size(); j++) {
                //compare words[i], words[j]
                int dict_j[26]; //words[i] consist of only lowercase English letters.
                for(int l=0; l<words[j].length(); l++) 
                    dict_j[words[j][l]-'a']++;
                
                int m = 0;
                while(m<26 && ( (dict_i[m]>0) && (dict_j[m]>0) || (dict_i[m]==0) && (dict_j[m]==0) ) ) {
                    m++;
                }
                if (m == 26)
                    ans++;
                for (int temp=0; temp<26; temp++) dict_j[temp] = 0;
            }

            for (int temp=0; temp<26; temp++) dict_i[temp] = 0;
        }

        return ans;

        
    }
};