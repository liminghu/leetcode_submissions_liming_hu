// https://leetcode.com/problems/remove-k-digits

/*
Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.
1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if( k == n )
            return "0";
        
        vector<bool> removed(n, false);

        int count = 0;
        for(int i=0; i<n; i++) {
            if(removed[i])
                continue;
            if(count == k)
                break;
            if(num[i]>=num[i+1] && removed[i]== false && removed[i+1]== false && num[i] != '0')
                removed[i] = true;
            else
                removed[i+1] = true;
            count++;
        }

        string ans = "";
        for(int i=0; i<n; i++) {
            if(removed[i]!=true)
                ans.push_back(num[i]);
        };
        while(ans[0] == '0' && ans.length() > 1)
            ans.erase(0, 1);
        return ans;
    }
};