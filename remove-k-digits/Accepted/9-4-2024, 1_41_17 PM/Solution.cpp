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
        if(k == 0)
            return num;
        
        string ans = "";
        stack<char> st; //top is the maximum.
        st.push(num[0]); ////n>=1
        for(int i=1; i<n; i++) {
            while(k>0 && !st.empty() && num[i] < st.top()) { //pop/remove greater numbers.
                st.pop();
                k--;
            };
            st.push(num[i]);
            // popping preceding zeroes
            if(st.size() == 1 && num[i] == '0') //if we push a "0" and only one element.
                st.pop();

        }

        while(k>0 && !st.empty()) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            ans.push_back( st.top() ); //maximum.
            st.pop();
        }
        reverse(ans.begin(), ans.end());


        while(ans[0] == '0' && ans.length() > 1)
            ans.erase(0, 1);
            
        if(ans.length() == 0)
            return "0";

        return ans;
    }
};