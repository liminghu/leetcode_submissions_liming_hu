// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

/*
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.
Given the head of a linked list with even length, return the maximum twin sum of the linked list.
The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105
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
    int pairSum(ListNode* head) {
        int res = 0;
        //i: 0.. n/2 -1
        //twin i: n-1.. (n-1)-(n/2)+1
        ListNode* cur = head;
        ListNode* fast = cur;
        if(head == NULL || head->next == NULL)
            return -1;
        int count = 0;
        while( fast ) {
            cur = cur->next;
            if(fast->next) 
                fast = fast->next->next;
        };

        //cur: it is the head of the second half.
        ListNode* second = reverse(cur);
        while(second) {
            res = max(res, second->val + head->val);
            head = head->next;
            second = second->next;
        };
        return res;
    }
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = reverse(head->next);
        ListNode* tail = newhead;
        while(tail->next)
            tail = tail->next;
        tail->next = head;
        head -> next = NULL;
        return newhead; 
    }
};