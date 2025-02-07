// https://leetcode.com/problems/guess-the-word

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {//10 <= allowedGuesses <= 30
        //words[i] is six letters long
        //words. Master.guess(word)   -1 
        int n = words.size();

        int matches = 0;
        for(int i=0; i<10 && matches<6; i++) {
            int random_idx = rand() % n;
            string guess = words[random_idx];
            matches = master.guess(guess);
            vector<string> wordlist2;
            for(string word:words) {
                if(getMatches(guess, word)==matches)
                    wordlist2.push_back(word);
            }
            words = wordlist2;
        }

    }
    int getMatches(string word1, string word2) {
        int matches = 0;
        for(int i=0; i<word1.length(); i++) {
            if(word1[i]==word2[i])
                matches++;
        }
        return matches;
    }
};