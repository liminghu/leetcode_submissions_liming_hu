// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        set<pair<int,int>> st;
        for(int i=0; i<nums.size(); i++)
            st.insert({nums[i], i});
        for(auto s:st) {
            if(nums[s.second] == -1) //marked.
                continue;
                score += s.first;
                nums[s.second] = -1;
                if(s.second-1>=0)
                    nums[s.second-1] = -1;
                if(s.second+1<nums.size())
                    nums[s.second+1] = -1;
        }
        return score;
    }
};