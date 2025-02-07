// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level

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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        while(!q.empty()) {
            int ls = q.size();
            vector<int> levelValues(ls);
            for(int i=0; i<ls; i++) {
                TreeNode* cur = q.front();
                q.pop();
                levelValues[i] = cur->val;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            ret += getMinSwaps(levelValues);
        }
        return ret;
    }
    int getMinSwaps(vector<int>& nums) { //unique.
        int ret = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> pos;
        for(int i=0; i<nums.size(); i++)
            pos[nums[i]] = i;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=sorted[i]) {
                ret++;
                int curPos = pos[sorted[i]];
                pos[nums[i]] = curPos;
                swap(nums[curPos], nums[i]);
            }
        }
        return ret;
    }
};