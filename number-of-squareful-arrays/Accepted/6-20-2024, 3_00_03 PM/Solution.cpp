// https://leetcode.com/problems/number-of-squareful-arrays

class Solution {
public:
    vector<vector<int>> next; 
    int visited[12];
    int sz;
    int ret = 0;

    int numSquarefulPerms(vector<int>& nums) {
        sz = nums.size();
        sort(nums.begin(), nums.end());
        next.resize(sz);

        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                if(i==j) continue;
                double sq = sqrt(nums[i]+nums[j]);
                if(sq == int(sq))
                    next[i].push_back(j);
            }
        }

        for(int i=0; i<sz; i++) {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            visited[i] = 1;
            dfs(nums, i, 1);
            visited[i] = 0;
        }

        return ret;
    }

    void dfs(vector<int>& nums, int cur, int count) {
        if(count == sz) {
            ret++;
            return;
        }
        int last = -1;
        for(int i: next[cur]) {
            if(visited[i] == 1) continue;
            if(nums[i]==last) continue;
            visited[i] = 1;            
            dfs(nums, i, count+1);
            last = nums[i];
            visited[i] = 0;
        }
    }


};