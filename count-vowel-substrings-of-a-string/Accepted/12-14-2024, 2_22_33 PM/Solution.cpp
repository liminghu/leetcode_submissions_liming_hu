// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
   int countVowelSubstrings(string word) {
        int vow = 0;
        int res = 0;
        int mp[256] = {};
        string vowels("aeiou");
        int r=0, l=0, k=0;
        for(; r<word.size(); r++) {
            if(vowels.find(word[r])!=string::npos) {
                mp[word[r]]++;
                vow += (mp[word[r]]==1);
                for(; vow==5; k++)  {//move to right.
                    mp[word[k]]--; 
                    vow -= (mp[word[k]]==0);
                }
                res += k - l;
            } else {
                mp['a'] = mp['e']=mp['i'] = mp['o'] = mp['u'] = 0;
                l = r+1;
                k = r+1;
                vow = 0;
            }
        }
        return res;
   }
    int countVowelSubstrings1(string word) {
        //A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
        int res = 0;
        int n = word.length();
        unordered_set<char> st;
        int i=0;
        while(i<n) {
            int j = i;
            for(; j<n; j++) {
                if(isVowel(word[j])== false) {
                    break;
                } 
                st.insert(word[j]);
                if(st.size()==5)
                    res++;
            }
            if(st.size()==5) {

            }
            //if(isVowel(word[j])== false)
            //    i = j+1;
            i++;
            st.clear();
        }
        return res;
    }
    bool isVowel(char c) {
        return c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u';
    }
};