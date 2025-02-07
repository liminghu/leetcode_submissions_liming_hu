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
            return false;
        if(start==end)
            return true;
        int root_val = preorder[start];
        if(end == start+1 ) 
            true;
        int i = -1;
        for(i=start+1; i<=end; i++) { //at least one element.
            if(preorder[i]>root_val)
                break;
        };
        if(i>0) {
            if( i <= end && preorder[i]>root_val) //has left and right.
                return verifyPreorder(preorder, start+1, i-1) && verifyPreorder(preorder, i, end);
            else //no left.
                return verifyPreorder(preorder, start+1, end);
        }
        return false;
    } 
};