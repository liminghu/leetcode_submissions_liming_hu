// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(int i=0; i<jewels.length(); i++)
            st.insert(jewels[i]);
        int count=0;
        for(int i=0; i<stones.length(); i++)
            if(st.find(stones[i])!=st.end())
                count++;
        return count;
    }
};