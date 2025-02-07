// https://leetcode.com/problems/odd-even-jump

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> odd(n, false);
        vector<bool> even(n, false);
        odd[n-1] = true;
        even[n-1] = true;
        map<int, int> mp;
        mp[arr.back()] = n-1;
        for(int i=n-2; i>=0; i--) {
            auto iter1 = mp.lower_bound(arr[i]);
            if(iter1!=mp.end()) {
                if(even[iter1->second])
                    odd[i] = true;
            }
            auto iter2 = mp.upper_bound(arr[i]);
            if(iter1 != mp.begin()) {
                iter2 = prev(iter2);
                if(odd[iter2->second])
                    even[i] = true;
            }            
            mp[arr[i]] = i;
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(odd[i])
                count++;
        }
        return count;
    }
};