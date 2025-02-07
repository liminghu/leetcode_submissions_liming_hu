// https://leetcode.com/problems/substring-with-concatenation-of-all-words

/*
You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are 
all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty() || words[0].size()==0 ) 
            return {};
        vector<int> res;
        int n = s.size(), num_words = words.size(), word_len = words[0].size();
        unordered_map<string, int> wordMap;
        for (string word : words) 
            wordMap[word]++;
        for (int i = 0; i < word_len; ++i) {
            int left = i, curCnt = 0;
            unordered_map<string, int> curMap;
            for (int j = i; j <= n - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                if (wordMap.count(word)) {
                    curMap[word]++;
                    if (curMap[word] <= wordMap[word]) { //find one match
                        curCnt++;
                    } else { //does not match.
                        while (curMap[word] > wordMap[word]) { //too much this substr.
                            string t = s.substr(left, word_len);
                            curMap[t]--;
                            if (curMap[t] < wordMap[t]) 
                                curCnt--;
                            left += word_len;
                        }
                    }
                    if (curCnt == num_words) { //find one, move left one word ahead.
                        res.push_back(left);
                        curMap[s.substr(left, word_len)]--;
                        curCnt--;
                        left += word_len;
                    }
                } else {
                    curMap.clear();
                    curCnt = 0;
                    left = j + word_len;
                }
            }
        }
        return res;
 
 /*       vector<int> res;
        unordered_map<string, int> word_dict;
        int len = words[0].size();
        int n = s.length(), num_words = words.size();
        for (const string& word : words) {
            word_dict[word]++;
        }
        for (int i = 0; i < len; i++) { //repeat the word length times.
            int cnt = 0;
            unordered_map<string, int> copy = word_dict;
            for (int j = i; j <= n - len; j += len) {
                string cur = s.substr(j, len);
                copy[cur]--;
                if (copy[cur] >= 0) { //find one word.
                    cnt++;
                }
                
                int pop_start = j - num_words * len; //the substr is too long?
                if (pop_start >= 0) {//the substr is too long.
                    string pop_word = s.substr(pop_start, len);
                    copy[pop_word]++; //put the word back.
                    if (copy[pop_word] > 0) { //if the word was in the substr before?
                        cnt--;
                    }
                }
                if (cnt == num_words) {
                    res.push_back(pop_start + len);
                }
            }
        }
        return res;*/
    }
};