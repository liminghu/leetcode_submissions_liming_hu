// https://leetcode.com/problems/goat-latin

class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U' });
        istringstream iss(sentence);
        string res;
        string word;
        int i=0;
        int j=0;
        while(iss>> word) {
            res += ' ' + 
            ( vowel.find(word[0])!= vowel.end()? word: word.substr(1)+word[0] )
            + "ma";
            i++;
            for(j=0; j<i; j++)
                res += 'a';
        }
        return res.substr(1);
    }
};