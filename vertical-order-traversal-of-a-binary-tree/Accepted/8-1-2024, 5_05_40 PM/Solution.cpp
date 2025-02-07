// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions 
(row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for 
each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort 
these nodes by their values. Return the vertical order traversal of the binary tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minRow = 0;
    int maxRow = 0;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /*
        The number of nodes in the tree is in the range [1, 1000].
        0 <= Node.val <= 1000
        */
        //<row, col>, val
        map<pair<int,int>, vector<int>> map1;

        traverse(root,  map1, 0, 0);

        vector<vector<int>>  res;
        vector<int> cols;
        unordered_set<int> visited;
        for(auto it=map1.begin(); it!=map1.end(); it++) { //get all the columns.
            if(visited.count(it->first.second) == 0) {
                cols.push_back(it->first.second); //col
                visited.insert(it->first.second);
            }
        }
        sort(cols.begin(), cols.end());

        for(int i=0; i<cols.size(); i++) {
            res.push_back(vector<int>());
            for(int j=minRow; j<=maxRow; j++) {
                pair<int, int> p = {j, cols[i]};
                if(map1.count(p)!=0) {
                    vector<int>& v = map1[p];
                    sort(v.begin(), v.end());
                    for(int num:v) {
                        res[res.size()-1].push_back(num);
                    }
                }
            }
        }
        return res;
    }

    void traverse(TreeNode* root,  map<pair<int,int>, vector<int>>& map1, int cur_row, int cur_col) {
            if(root==nullptr)
                return;
            map1[{cur_row,cur_col}].push_back(root->val);
            maxRow = max(maxRow, cur_row);
            traverse(root->left,  map1, cur_row+1, cur_col-1);
            traverse(root->right,  map1, cur_row+1,cur_col+1);
        }
};