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
        multimap<int, int> mp;
        mp.insert({arr.back(), n-1});
        for(int i=n-2; i>=0; i--) {
            int v = arr[i];
            if(mp.find(v)!=mp.end()) {
                auto it = mp.find(v);
                odd[i] = even[it->second];
                even[i] = odd[it->second];
            }
            auto iter1 = mp.lower_bound(v); //>=arr[i]
            if( iter1 != mp.end() ) {
                if(even[iter1->second])
                    odd[i] = true;
            }
            auto iter2 = mp.upper_bound(v); //>arr[i]     <=
            if(iter1 != mp.begin()) {
                iter2 = prev(iter2, 1);
                if(odd[iter2->second])
                    even[i] = true;
            }            
            mp.insert({v,i});
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(odd[i])
                count++;
        }
        return count;
    }
};