// https://leetcode.com/problems/next-greater-node-in-linked-list

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
class Solution {
public:
    /*
    You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
    */
    vector<int> nextLargerNodes(ListNode* head) { //The number of nodes in the list is n;  1 <= n <= 104; 1 <= Node.val <= 109
        vector<int> nextLarger;
        
        if(head==nullptr)
            return nextLarger;
        if(head->next == nullptr) {
            nextLarger.push_back(0);
            return nextLarger;
        };
            
        
        ListNode* cur = head;
        ListNode* nextgreater=cur->next;
        
        while(cur!=nullptr) {
            nextgreater=cur->next;
            while(nextgreater!=nullptr && nextgreater->val <=cur->val) {
                nextgreater = nextgreater->next;
            };
            if(nextgreater!=nullptr)
                nextLarger.push_back(nextgreater->val);
            else
                nextLarger.push_back(0);
            
            cur = cur->next;
            
        }
       // nextLarger.push_back(0);
        return nextLarger;
    }
};