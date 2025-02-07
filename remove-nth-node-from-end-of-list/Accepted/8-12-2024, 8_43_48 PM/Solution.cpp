// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* slow = fakehead;
        ListNode* fast = fakehead;
        while(n>0 && fast !=nullptr) {
            fast = fast->next;
            n= n-1;
        };
       // cout << "fast:" << fast->val << endl;
        if(fast == nullptr && n>0)
            return head;
        
        ListNode* cur = slow;
        while(fast != nullptr) {
            fast = fast->next;
            cur = slow;
            slow = slow->next;
        };
        cur->next = slow->next;
        return fakehead->next;
    }
};