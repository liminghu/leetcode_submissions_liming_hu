// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
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