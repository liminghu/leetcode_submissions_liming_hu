// https://leetcode.com/problems/ipo

/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to 
work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct
 projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
The answer is guaranteed to fit in a 32-bit signed integer.
1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //at most k distinct projects 
        //n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
        //Initially, you have w capital
        int n = profits.size();
        vector<pair<int,int>> cap_pro(n,{0,0});
        for(int i=0; i<n; i++) {
            cap_pro[i].first  = capital[i];
            cap_pro[i].second = profits[i];
        };
        sort(cap_pro.begin(), cap_pro.end()); //non decreasing by capital.

        if(w < cap_pro[0].first)
            return 0;
        int ans = 0;
        priority_queue<int> pq; //max queue.
        int i = 0;
        int count = 0;
        while(count < k) {
            while(i<cap_pro.size() && cap_pro[i].first <=w) {
                pq.push(cap_pro[i].second);
                i++;
            };
            
            if(pq.empty())
                break;

            w += pq.top();
            pq.pop();
            count++;
        };
        return w;
    }
};