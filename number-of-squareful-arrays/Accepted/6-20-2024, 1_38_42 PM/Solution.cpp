// https://leetcode.com/problems/number-of-squareful-arrays

class Solution {
public:
unordered_map<int, int> count;
    unordered_map<int, unordered_set<int>> cand;
    int res = 0;
    int numSquarefulPerms(vector<int>& A) {
        for (int &a : A) count[a]++;
        for (auto &i : count) {
            for (auto &j : count) {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y)
                    cand[x].insert(y);
            }
        }
        for (auto e : count)
            dfs(e.first, A.size() - 1);
        return res;
    }

    void dfs(int x, int left) {
        count[x]--;
        if (!left) res++;
        for (int y : cand[x])
            if (count[y] > 0)
                dfs(y, left - 1);
        count[x]++;
    }
};