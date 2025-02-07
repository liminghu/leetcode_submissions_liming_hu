// https://leetcode.com/problems/pancake-sorting

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
    /*
    Find the index i of the next maximum number x.
    Reverse i + 1 numbers, so that the x will be at A[0]
    Reverse x numbers, so that x will be at A[x - 1].
    Repeat this process N times.

    Update:
    Actually, I didn't use the condition permutation of [1,2,..., A.length].
    I searched in the descending order of A.

    Time Complexity:
    O(N^2)
    */
        vector<int> res;
        int x, i;
        for(x = A.size(); x>0; --x) {  //simlary to bubble sort. 
            for(i=0; A[i] !=x; i++); //Find the index i of the next maximum number x.
            reverse(A.begin(), A.begin() + i + 1); //Reverse i + 1 numbers, so that the x will be at A[0]
            res.push_back(i+1);
            reverse(A.begin(), A.begin()+x); //Reverse x numbers, so that x will be at A[x - 1].
            res.push_back(x);
        }
        return res;
    }
};