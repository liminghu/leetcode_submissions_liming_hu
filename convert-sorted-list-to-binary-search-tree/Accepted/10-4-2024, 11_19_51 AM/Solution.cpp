// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/*Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.
 Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []

 Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        };
        //we have at least two nodes.
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        };
        //root: slow
        TreeNode* root = new TreeNode(slow->val);
        //right = (slow->next, fast)
        TreeNode* right = sortedListToBST(slow->next);
        //left = (head, prev)
        prev->next = NULL; //break the linked list.
        TreeNode* left = sortedListToBST(head);
        root->left = left;
        root->right = right;
        return root;        
    }
};