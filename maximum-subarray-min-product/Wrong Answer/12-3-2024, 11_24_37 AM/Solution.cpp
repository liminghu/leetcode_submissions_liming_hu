// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) {
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
        vector<long long> preSum(n, 0);
        for(int i=0; i<n; i++) {
            if(i==0)
                preSum[i] = arr[i];
            else
                preSum[i] = preSum[i-1]+arr[i];
        }

        long long ret = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++) {
            int min = arr[i];
            int right = nextSmaller[i];
            int left = prevSmaller[i];
            long long sum = preSum[right-1];
            if(left != -1)
                sum = preSum[right-1]-preSum[left];
            long long prod = sum*min;
            if(prod > ret)
                ret = prod%mod;
        }     
        return ret;        
    }
};