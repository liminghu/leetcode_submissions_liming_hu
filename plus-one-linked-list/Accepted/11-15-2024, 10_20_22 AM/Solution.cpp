// https://leetcode.com/problems/plus-one-linked-list

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
    ListNode* plusOne(ListNode* head) {
        if(head==NULL) {
            ListNode* nl = new ListNode(1);
            return nl;
        }
        int carry = 1;
        ListNode* newhead = reverseList(head);
        ListNode* cur = newhead;
        ListNode* prev;
        while(cur && carry == 1) {
            int new_carry = (cur->val + carry) / 10;
            cur->val = (cur->val +  carry) % 10;
            carry = new_carry;
            prev = cur;
            cur = cur->next;
        }
        if(carry) {
            ListNode* nl = new ListNode(carry);
            prev->next = nl; 
        };
        return reverseList(newhead);

    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        ListNode* prev = NULL;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};