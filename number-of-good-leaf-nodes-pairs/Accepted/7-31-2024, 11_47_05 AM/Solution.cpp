// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs

/*
You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is 
said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.
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
private:
    vector<int> postOrder(TreeNode* currentNode, int distance) {
        if (!currentNode)
            return vector<int>(12);
        else if (!currentNode->left && !currentNode->right) { //leaf
            vector<int> current(12);
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right, distance);

        vector<int> current(12);

        // Combine the counts from the left and right subtree and shift by
        // +1 distance
        for (int i = 0; i < 10; i++) { //1... 10
            current[i + 1] = left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and
        // right subtrees.
        current[11] += left[11] + right[11];

        // Iterate through possible leaf node distance pairs
        for (int d1 = 0; d1 <= distance; d1++) {
            for (int d2 = 0; d2 <= distance; d2++) {
                if (2 + d1 + d2 <= distance) {
                    // If the total path distance is less than the given
                    // distance limit, then add to the total number of good
                    // pairs.
                    current[11] += left[d1] * right[d2];
                }
            }
        }

        return current;
    }


public:
    int countPairs(TreeNode* root, int distance) {
        /*The number of nodes in the tree is in the range [1, 210].
            1 <= Node.val <= 100
            1 <= distance <= 10 
        */

        return postOrder(root, distance)[11];




 /*       int res = 0;      
        unordered_map< TreeNode*, vector<TreeNode*> > graph;
        unordered_set<TreeNode*> leafNodes;   
        findChildren(root, nullptr, graph, leafNodes);
        if(leafNodes.size() < 2 )
            return 0;
        
        for(auto leaf: leafNodes) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> seen;
            q.push(leaf);
            seen.insert(leaf);
            for(int i=0; i<=distance; i++) {
                int size = q.size();
                for(int j=0; j<size; j++) {
                    TreeNode* cur = q.front();
                    q.pop();
                    if(leafNodes.count(cur) && cur != leaf) 
                        res++;
                    if(graph.count(cur)) {
                        for(auto neighbor: graph[cur]) {
                            if(!seen.count(neighbor)) {
                                q.push(neighbor);
                                seen.insert(neighbor);
                            }
                        }
                    }
                }
            }
        }

        return res/2;*/
    }

    //transform the tree to undirected graph, and find all the leafs.
/*    void findChildren(TreeNode* cur, TreeNode* parent, unordered_map< TreeNode*, vector<TreeNode*> >& graph, unordered_set<TreeNode*>& leaf ) {
        if(cur == nullptr)
            return;
        if(cur->left == nullptr && cur->right == nullptr) {
            leaf.insert(cur);
        }

        if(parent) {
            graph[parent].push_back(cur);
            graph[cur].push_back(parent);
        }

        findChildren(cur->left, cur, graph, leaf);
        findChildren(cur->right, cur, graph, leaf); 
    }*/
};