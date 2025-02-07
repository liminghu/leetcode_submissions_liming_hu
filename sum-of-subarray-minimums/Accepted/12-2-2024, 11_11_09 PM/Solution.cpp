// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller(n, n);
        vector<int> prevSmaller(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }   
        long ret = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++) {
            long count = (i-prevSmaller[i])*(nextSmaller[i]-i)%mod;
            ret = (ret+count*arr[i])%mod;
        }     
        return ret;

    }
    int sumSubarrayMins1(vector<int>& arr) {
       int mod = 1e9+7;
       stack<int> st; // stack.
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