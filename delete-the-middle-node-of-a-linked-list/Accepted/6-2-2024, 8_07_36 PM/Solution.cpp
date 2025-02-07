// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int count=0;  //⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
        if(head==NULL)
            return NULL;
        if(head->next == NULL) 
            return NULL;
        
        ListNode* pre_slow = slow;        
        while(fast!=NULL && fast->next != NULL) {
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        };

        //delete pre_slow->next;
        pre_slow->next = slow->next;
        return head;
    }
};