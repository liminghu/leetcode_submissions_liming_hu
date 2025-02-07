// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        //index i, you can jump to i + arr[i] or i - arr[i]
        //check if you can reach any index with value 0.
        return dfs(arr, start);
    }
    bool dfs(vector<int>& arr, int start) {
        if(start <0 || start >= arr.size() || arr[start] < 0) //negative: visited.
            return false;
        if(arr[start]==0)
            return true;
        arr[start] = -arr[start];
        return dfs(arr, start+arr[start]) || dfs(arr, start-arr[start]);
    }
};