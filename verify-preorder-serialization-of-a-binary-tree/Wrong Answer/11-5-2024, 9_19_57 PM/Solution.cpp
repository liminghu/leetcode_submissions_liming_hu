// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int degree = 1;
        for(int i=0; i<n; i++) {
            if(preorder[i] == ',')
                continue;
            degree--;
            if(degree < 0)
                return false;
            if(preorder[i] != '#')
                degree+=2;
        }
        return degree == 0;
    }
};