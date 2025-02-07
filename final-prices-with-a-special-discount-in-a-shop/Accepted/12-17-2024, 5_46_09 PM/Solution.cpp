// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        stack<pair<int, int>> stackp;
        //For every price, find a higher or equal price before and discount it. Keep all unprocessed price in stack
        for(size_t i=0; i< prices.size(); i++) {
            while ((!stackp.empty()) && stackp.top().first >=prices[i]) {
                result[stackp.top().second] -=prices[i];
                stackp.pop();
            }
            stackp.push(make_pair(prices[i], i));
            result.push_back(prices[i]);
        }
        return result;
    }
};