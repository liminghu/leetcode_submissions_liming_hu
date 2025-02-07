// https://leetcode.com/problems/number-of-boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //You are given n points in the plane that are all distinct, where points[i] = [xi, yi]
        int n = points.size();
        //A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
        int res = 0;
        if(n<=2)
            return 0;
        for(int i=0; i<n; i++) {
            unordered_map<long long, int> group(n);
            for(int j=0; j<n; j++) {
                if(j==i)
                    continue;
                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];
                int key = dy*dy+dx*dx;
                group[key]++;
            }
            for(auto& p:group) {
                if(p.second > 1) {
                    res += p.second*(p.second-1);
                }
            }
        }
        return res;
    }
};