// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        //Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
        vector<int> rets;
        int i=1, j=n; 
        while( i <= j ) {
            if(k>1) {
                if(k%2==1) {
                    rets.push_back(i);
                    i++;
                } else {
                    rets.push_back(j);
                    j--;
                }
                k--;
            }  else {
                rets.push_back(i);
                i++;
            }
        }
        return rets;
    }
};