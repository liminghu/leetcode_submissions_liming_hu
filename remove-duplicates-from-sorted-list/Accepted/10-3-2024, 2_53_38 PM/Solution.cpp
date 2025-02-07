// https://leetcode.com/problems/remove-duplicates-from-sorted-list

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        ListNode* prev = head;
        while(cur) {
            while( cur && prev->val == cur->val ) 
                cur = cur->next;
            if( prev != cur )
                prev->next = cur;
            else if(prev == cur) 
                cur = cur->next;
            prev = cur;
        }
        return head;
    }
};