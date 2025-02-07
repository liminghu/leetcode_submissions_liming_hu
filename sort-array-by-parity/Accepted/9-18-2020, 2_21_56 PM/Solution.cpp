// https://leetcode.com/problems/sort-array-by-parity


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //easy, two pointers.
        int even_idx =0;
        int odd_idx = A.size()-1;
        vector<int> ans;
        while(even_idx < odd_idx) {
            while (even_idx < A.size() - 1 && A[even_idx] % 2 == 0) even_idx++;
            while( odd_idx > 0 && A[odd_idx] % 2 == 1 ) odd_idx--;
            if(even_idx < odd_idx) {
                swap(A[even_idx], A[odd_idx]);
                even_idx++;
                odd_idx--;
            }
        };
        ans = A;
        return A;
    }
};
