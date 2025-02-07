// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9+7;
        unordered_set<long long> hSet; 
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i=0; i<hFences.size(); i++) {
            for(int j=i+1; j<hFences.size(); j++) 
                hSet.insert( hFences[j]-hFences[i] );
        };

        long long ans = 0;
        for(int i=0; i<vFences.size(); i++) {
            for(int j=i+1; j<vFences.size(); j++) {
                if(hSet.find( vFences[j]-vFences[i] ) != hSet.end()) 
                    ans = max(ans, (long long)( vFences[j]-vFences[i] ) );
            };
        };       

        if( ans == 0 )
            return -1;
        return ( ans * ans ) % mod;
    }
};