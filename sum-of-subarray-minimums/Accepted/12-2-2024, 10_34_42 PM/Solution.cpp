// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int mod = 1e9+7;
       stack<int> st;
       long sumOfMin = 0;
       for(int i=0; i<=arr.size(); i++) {
            while(!st.empty() && (i==arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty()? -1: st.top();
                int right = i;
                long long count = (mid-left)*(right-mid)%mod;
                sumOfMin += (count*arr[mid])%mod;
                sumOfMin %= mod;
            }
            st.push(i);
       } 
       return (int)sumOfMin;
    }
};