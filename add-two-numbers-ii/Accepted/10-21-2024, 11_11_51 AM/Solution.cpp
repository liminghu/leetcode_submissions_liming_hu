// https://leetcode.com/problems/add-two-numbers-ii

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of 
their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 
Follow up: Could you solve it without reversing the input lists?
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        //add the result
        int carry = 0;
        while(l1 && l2) {
            int sum = (carry + l1->val + l2->val) % 10;
            carry = (carry + l1->val + l2->val) / 10;
            ListNode* newnode = new ListNode(sum);
            cur->next = newnode;
            cur = newnode;
            l1 = l1->next;
            l2 = l2->next;
        };

        while(l1) { //l2 is null
            int sum = (carry + l1->val) % 10;
            carry = (carry + l1->val) / 10;
            ListNode* newnode = new ListNode(sum);
            cur->next = newnode;
            cur = newnode;
            l1 = l1->next;     
        };
        while(l2) { //l1 is null
            int sum = (carry + l2->val) % 10;
            carry = (carry + l2->val) / 10;
            ListNode* newnode = new ListNode(sum);
            cur->next = newnode;
            cur = newnode;
            l2 = l2->next;     
        };        
        if(carry) {
           ListNode* newnode = new ListNode(carry);
            cur->next = newnode;
            cur = newnode;              
        }
        res = res->next;

        return reverseList(res);
    }

    ListNode* reverseList(ListNode* root) {
        ListNode* cur = root;
        ListNode* next;
        ListNode* prev = NULL;
        while(cur) {
            next = cur->next; //keep the next.
            cur->next = prev;
            prev = cur;
            cur = next;
        };
        return prev;
    }
};