// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //You are given two 0-indexed integer permutations A and B of length n.
        int n = A.size();
        vector<int> C;
        unordered_set<int> Aset;
        unordered_set<int> Bset;
        unordered_set<int> Cset;
        for(int i=0; i<n; i++) {
            if(A[i]==B[i]) {
                Cset.insert(A[i]);
            } else {
                if(Aset.count(B[i]))
                     Cset.insert(B[i]);
                if(Bset.count(A[i]))
                    Cset.insert(A[i]);
            }
            Aset.insert(A[i]);
            Bset.insert(B[i]);
            C.push_back(Cset.size());
        }
        return C;
    }
};