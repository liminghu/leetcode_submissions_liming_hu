// https://leetcode.com/problems/stickers-to-spell-word

/*
We are given n different types of stickers. Each sticker has a lowercase English word on it.
You would like to spell out the given string target by cutting individual letters from your collection
 of stickers and rearranging them. You can use each sticker more than once if you want, and you have 
 infinite quantities of each sticker.
Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and 
target was chosen as a concatenation of two random words.
*/
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        /*  n == stickers.length
            1 <= n <= 50
            1 <= stickers[i].length <= 10
            1 <= target.length <= 15
            stickers[i] and target consist of lowercase English letters.
        */
        int n = target.size();
        int N = (1<<n);
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;

        for(int i=0; i<N; i++) {
            if(dp[i] == INT_MAX)
                continue;
            for(auto str:stickers) {
                int j = findNextStatus(i, target, str);  //j > i
                if(j>i)
                    dp[j] = min(dp[j], dp[i]+1);
            };
        }
        return dp[N-1]==INT_MAX? -1: dp[N-1];
    }
    int findNextStatus(int status, string target, string sticker) {
        int n = target.size();
        for(auto ch:sticker) {
            for(int k=0; k<n; k++) {
                if( ( (status>>k)&1 ) == 0 && target[k] == ch ) {
                    status += (1<<k);
                    break;
                }
            }
        }
        return status;
    }
};