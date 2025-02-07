// https://leetcode.com/problems/divide-chocolate

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int l = 1;
        int r = 1e9/(k+1);
        while(l<r) {
            int mid = (l+r+1)/2;
            int cur = 0, cuts = 0;
            for(int a: sweetness) {
                cur += a;
                if( cur >= mid) {
                    cur = 0;
                    if(++cuts > k)
                        break;
                }
            }
            if(cuts > k) 
                l = mid;
            else
                r = mid -1;
        }
        return l;
    }
};