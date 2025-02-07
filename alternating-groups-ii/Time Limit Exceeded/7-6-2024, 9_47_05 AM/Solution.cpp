// https://leetcode.com/problems/alternating-groups-ii

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) { //3 <= colors.length <= 105; 0 <= colors[i] <= 1; 3 <= k <= colors.length
       unsigned int sz = colors.size();
        if( sz < k )
            return 0;
        
        int ans = 0;
        //bool found;
        for( unsigned int i = 0; i < sz; i++ ) {
            int count = 0;
            for(int j=i; j<i+k-2; j++) {
                if( colors[j % sz] != colors[ (j+1+sz) % sz ] && colors[(j+1+sz) % sz ] != colors[ (j+2+sz) % sz ] ) {
                    count++;
                    //cout << i << endl;
                    //cout << colors[ (i-1) % sz ] << " " << colors[ i ] << " "<< colors[ (i+1) % sz ] << " " << endl;
                    //cout << "ans = " << ans << endl;
                } else {
                    break;
                }
            }
            if( count == k-2 ) {
                ans++;
                count = 0;
            }
        }
        
        return ans;        
    }
};