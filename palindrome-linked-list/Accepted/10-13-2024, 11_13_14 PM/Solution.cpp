// https://leetcode.com/problems/palindrome-linked-list

/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        if(head->next==NULL)
            return true;

        ListNode* firsthalfEnd = endofFirstHalf(head);
        ListNode* secondHalfReverse = reverseList(firsthalfEnd->next);
        bool res = true;
        ListNode* p1 = head;
        ListNode* p2 = secondHalfReverse;
        while( res && p2!=NULL) {
            if(p1->val != p2->val)
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        firsthalfEnd->next = reverseList(secondHalfReverse);
        return res;
    }
    ListNode* endofFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur!=NULL) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};