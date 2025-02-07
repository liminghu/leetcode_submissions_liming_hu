// https://leetcode.com/problems/number-of-valid-words-in-a-sentence

class Solution {
public:
    int countValidWords(string sentence) {
        istringstream iss(sentence);
        string word;
        int count = 0;
        string puncs = "!.,";
        while(iss>>word) {
            int i=0;
            int hyphen = 0;
            for(; i<word.length(); i++) {
                if(isdigit(word[i]))
                    break;
                if(word[i]=='-')
                    hyphen++;
                if(hyphen>1)
                    break;
                if(hyphen && (i==0 || i==word.length()-1 ) )
                    break;
                if(hyphen && ( !islower(word[i-1]) || !islower(word[i+1])) )
                    break;
                if((word[i]=='!' || word[i]=='.' || word[i]=='"') && i!=word.length()-1)
                    break;
            }
            if(i==word.length())
                count++;
        }
        return count;
    }
};