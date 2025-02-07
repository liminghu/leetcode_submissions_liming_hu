// https://leetcode.com/problems/optimal-account-balancing

/*You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] 
indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.
Return the minimum number of transactions required to settle the debt.
*/
class Solution {
private:
    int dfs(int idx, vector<int>& balance) {
        if(idx == balance.size())
            return 0; //no transaction needed.
        int cur = balance[idx];
        if(cur == 0)  //no transaction needed for current idx.
            return dfs(idx+1, balance);
        
        int min_transactions = INT_MAX;

        for(int i=idx+1; i<balance.size(); i++) {
            int next = balance[i];
            if(cur*next < 0) { //one is "should be paid" (+), the other is "should pay." (-)
                balance[i] = next + cur; //should be paid (+)
                balance[idx] = 0; //it does not matter.
                min_transactions = min(min_transactions, 1+dfs(idx+1, balance));
                balance[idx] = cur;
                balance[i] = next;

                if(next + cur == 0)
                    break;
            }
        }
        return min_transactions;
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        //transactions[i] = [fromi, toi, amounti]
        /*
            1 <= transactions.length <= 8
            transactions[i].length == 3
            0 <= fromi, toi < 12
            fromi != toi
            1 <= amounti <= 100
        */
        unordered_map<int, int> mp; //account, balance.
        for(int i=0; i<transactions.size(); i++) {
            mp[transactions[i][0]] += transactions[i][2]; //should be paid.
            mp[transactions[i][1]] -= transactions[i][2]; //should pay.
        }

        vector<int> balance;
        for(auto iter: mp) {
            if(iter.second != 0 ) {
                balance.push_back(iter.second);
            }
        }
        return dfs(0, balance);
    }
};