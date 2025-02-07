// https://leetcode.com/problems/alternating-groups-i

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) { //colors[i] == 0 means that tile i is red.
                                                        //colors[i] == 1 means that tile i is blue
        unsigned int sz = colors.size();
        if(sz<3)
            return 0;
        
        int ans = 0;
        for(int i=0; i<=sz; i++) {
            if(colors[i] != colors[(i-1)%sz] && colors[i] != colors[(i+1)%sz])
                ans++;
        }
        
        return ans;
        
    }
};