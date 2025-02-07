// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) { //789
        vector<int> rets;
        int cur = 1;
        for(int i=0; i<n; i++) {
            rets.push_back(cur);
            if( cur * 10 <= n )
                cur *= 10;
            else {
                while(cur % 10 == 9 || cur >= n) { //last digit is 9, or exceed the limits.
                    cur /= 10;   //remove the last digit.
                };
                cur++;
            }
        }
        return rets;
        /*vector<string> res;
        for(int i=1; i<=n; i++) {
            res.push_back(to_string(i));
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(int i=1; i<=n; i++) {
            ans.push_back(stoi(res[i-1]));
        }
        
        return ans;*/
    }
};