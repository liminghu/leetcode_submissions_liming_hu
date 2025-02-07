// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++)
            st.insert(candyType[i]);
        return min(n/2, (int)st.size());
    }
};