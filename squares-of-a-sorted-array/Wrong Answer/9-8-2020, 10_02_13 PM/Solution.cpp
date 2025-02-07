// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0);

        //merge sort;
        int i=0; 
        int j=A.size()-1;
        if(A.size() <=1) return ans;
        for(int p=A.size()-1; p >= 0; p--) {
            if(abs(A[i]) > abs(A[j])) {
                ans[p] = A[i]*A[i];
                i++;
            } else {
                ans[p] = A[j]*A[j];
                j--;
            }        
       }
        return ans;
        
    }
};