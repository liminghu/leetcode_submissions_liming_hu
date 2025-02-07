// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n<=1)
            return true;
        return verifyPreorder(preorder, 0, n-1);
    }
    bool verifyPreorder(vector<int>& preorder, int start, int end) {
        if(start>=preorder.size() || end>=preorder.size() || start > end) //invalid
            return true;
        if(start==end)
            return true;
        int root_val = preorder[start];
        if(end == start+1 ) 
            return true;
        int i = -1;
        for(i=start+1; i<=end; i++) { //at least 2 elements.
            if(preorder[i]>root_val)
                break;
        };
        if(i>0) {
            if( i <= end) 
                return verifyPreorder(preorder, start+1, i-1) && verifyPreorder(preorder, i, end);
            else //  i = end+1;  all elements less than root. 
                return false;
        }
        return false;
    } 
};