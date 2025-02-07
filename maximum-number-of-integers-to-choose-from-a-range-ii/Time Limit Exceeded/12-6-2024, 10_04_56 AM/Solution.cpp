// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii

class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        unordered_set<int> st;
        for(auto& ban: banned)
            st.insert(ban);
        int count = 0;
        long long sum = 0;
        for(int i=1; i<=n; i++) {
            if(st.count(i))
                continue;
            if(sum+i >maxSum)
                break;
            count++;
            sum += i;
        };
        return count;        
    }
};