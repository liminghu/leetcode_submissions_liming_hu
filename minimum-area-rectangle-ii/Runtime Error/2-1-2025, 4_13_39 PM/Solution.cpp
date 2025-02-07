// https://leetcode.com/problems/minimum-area-rectangle-ii

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) { //1 <= points.length <= 50
        //points[i] = [xi, yi].
        int n = points.size();
        int ret = 0;
        unordered_map<int, unordered_map<int, vector<vector<int>>>> mp; //key: distance between 2 points.
        if(n<=3)
            return 0.0;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 =  points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 =  points[j][1];
                int len = d2(x1,y1, x2, y2);
                auto center = ( (x1+x2)<<16 ) + (y1+y2);
                mp[center][len].push_back({x1, y1, x2, y2});
            }
        }
        for(auto it_c = mp.begin(); it_c != mp.end(); it_c++) {//mp[center]
            for(auto it_l = (it_c->second).begin(); it_l!=(it_c->second).end(); it_l++) { //mp[center][len]
                for(int i=0; i<(it_l->second).size(); i++ ) { //{x1, y1, x2, y2}, {x1, y1, x2, y2}
                    for(int j=i+1; j<(it_l->second).size(); j++ ) { //{x1, y1, x2, y2}
                        auto& p1 = (it_l->second)[i];//{x1, y1, x2, y2}
                        auto& p2 = (it_l->second)[j]; //{x3, y3, x4, y4}
                        auto d = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
                        if(ret==0 || ret>d)
                            ret = d;
                    }
                }
            }
        }
        return sqrt(ret);
    }
    int d2(int x1, int y1, int x2, int y2) {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
};