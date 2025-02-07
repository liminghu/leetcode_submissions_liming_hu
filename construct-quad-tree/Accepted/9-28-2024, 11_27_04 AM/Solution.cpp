// https://leetcode.com/problems/construct-quad-tree

/*
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.
Return the root of the Quad-Tree representing grid.
A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:
val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to 
True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:
If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
If you want to know more about the Quad-Tree, you can refer to the wiki.
Quad-Tree format:
You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized 
format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.
It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].
If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.
n == grid.length == grid[i].length
n == 2x where 0 <= x <= 6
*/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size()-1, grid[0].size()-1);
    }

    Node* helper(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        if(x1>x2 || y1 > y2)
            return NULL;
        int val = grid[x1][y1];
        bool same = true;
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                if(grid[i][j] != val)
                    same = false;
            }
        };

        Node* node = new Node();
        if(same) {
            node->isLeaf = true;
            node->val = grid[x1][y1];
            return node;
        };

        int rowMid = (x1+x2)/2;  
        int colMid = (y1+y2)/2;
        node->isLeaf = false;
        node->topLeft = helper(grid, x1, y1, rowMid, colMid);
        node->topRight = helper(grid, x1, colMid+1, rowMid, y2);
        node->bottomLeft = helper(grid, rowMid+1, y1, x2, colMid);
        node->bottomRight = helper(grid, rowMid+1, colMid+1, x2, y2);
        return node;
    }
};