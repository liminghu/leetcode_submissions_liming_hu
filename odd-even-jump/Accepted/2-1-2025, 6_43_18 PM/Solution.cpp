// https://leetcode.com/problems/odd-even-jump

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)
            return n;
        vector<bool> odd(n, false);
        vector<bool> even(n, false);
        odd[n-1] = true;
        even[n-1] = true;
        map<int, int> mp;
        mp[arr.back()]=n-1;
        for(int i=n-2; i>=0; i--) {
            int v = arr[i];
            auto lo = mp.lower_bound(v); //>=arr[i]
            if( lo != mp.end() ) {
                if(even[lo->second])
                    odd[i] = true;
            }
            auto hi = mp.upper_bound(v); //>arr[i]     <=
            if(hi != mp.begin()) {
                hi = prev(hi, 1);
                if(odd[hi->second])
                    even[i] = true;
            }            
            mp[v] = i;
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(odd[i])
                count++;
        }
        return count;
    }
};