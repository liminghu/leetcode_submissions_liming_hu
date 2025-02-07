// https://leetcode.com/problems/number-of-orders-in-the-backlog

using PII = pair<int, int>;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {//orders[i] = [pricei, amounti, orderTypei]
        //orderTypei: 0(buy), 1(sell)
        priority_queue<PII, vector<PII>, greater<>> sell_pq;   //pricei, amounti
        priority_queue<PII, vector<PII>> buy_pq;   //pricei, amounti      
        long count = 0;
        long M = 1e9+7;
        for(auto order:orders) {
            int pricei = order[0]; 
            int amounti = order[1];
            int orderTypei = order[2];
            count = (count+amounti)%M;
            if(orderTypei==0) { //buy
                while(!sell_pq.empty() && amounti>0 && sell_pq.top().first <=pricei) {
                    auto [s_price, s_amount] = sell_pq.top();
                    sell_pq.pop();
                    long num = min(s_amount, amounti);
                    s_amount -= num;
                    amounti -= num;
                    count = (count-num*2+M)%M;
                    if(s_amount > 0)
                        sell_pq.push({s_price, s_amount});            
                }
                if(amounti>0)
                    buy_pq.push({pricei, amounti});
            } else { //sell
                while(!buy_pq.empty() && amounti>0 && buy_pq.top().first >=pricei) {
                    auto [b_price, b_amount] = buy_pq.top();
                    buy_pq.pop();
                    long num = min(b_amount, amounti);
                    b_amount -= num;
                    amounti -= num;
                    count = (count-num*2+M)%M;
                    if(b_amount > 0)
                        buy_pq.push({b_price, b_amount});            
                }
                if(amounti>0)
                    sell_pq.push({pricei, amounti});
            }   
        }
        return count;
    }
};