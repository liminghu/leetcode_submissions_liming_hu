// https://leetcode.com/problems/image-overlap

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> vec1;
        vector<pair<int,int>> vec2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(img1[i][j] == 1)
                    vec1.push_back({i,j});
                if(img2[i][j] == 1)
                    vec2.push_back({i,j});
            }
        }

        int ans = 0;
        unordered_map<string,int> mp;
        for(auto [r1, c1]:vec1) {
            for(auto [r2, c2]: vec2) {
                string key = to_string(r1-r2)+"_"+to_string(c1-c2);
                mp[key]++;
                ans = max(ans, mp[key]);
            }
        }
        return ans;
    }
};