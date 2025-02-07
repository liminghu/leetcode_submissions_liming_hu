// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int nodes = 1; //We use nodes to count the nodes we are allowed to have next.
        while(getline(ss, curr, ',')) { //If we get a non-null node, we can have after it two more nodes.
            nodes--;
            if(nodes < 0)
                return false;
            if(curr != "#")
                nodes += 2;
        }
        return nodes == 0; //At the end, we are supposed to end up with nodes == 0, otherwise the tree is not good.
    }
};