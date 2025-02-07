// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9+7;
        set<long long> hSet; //ordered
        set<long long> vSet; //ordered
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i=0; i<hFences.size(); i++) {
            for(int j=i+1; j<hFences.size(); j++) {
                hSet.insert(hFences[j]-hFences[i]);
            };
        };
        for(int i=0; i<vFences.size(); i++) {
            for(int j=i+1; j<vFences.size(); j++) {
                vSet.insert(vFences[j]-vFences[i]);
            };
        };       
        long long ans = 0;
        for(auto h:hSet) {
            if(vSet.find(h) !=vSet.end() ) {
                long long area = (long long) (h*h);
                if(area > ans)
                    ans = area % mod;
            }
        };
        if(ans==0)
            return -1;
        return ans % mod;
    }
};