// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseDict = {".-","-...","-.-.","-..",".","..-.","--.", "....","..",".---","-.-",".-..","--","-.", "---",".--.","--.-",".-.","...","-","..-", "...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto& word: words) {
            string encoded = "";
            for(auto c: word)
                encoded +=  morseDict[c-'a'];
            st.insert(encoded);
        }
        return st.size();
    }
};