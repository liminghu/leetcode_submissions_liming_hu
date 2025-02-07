// https://leetcode.com/problems/partition-list

/*
Given the head of a linked list and a value x, partition it such that all nodes 
less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        
        ListNode* fakehead = new ListNode(INT_MAX, head);
        //find the first node whose value is greater than or equal to x.
        ListNode* cur = head;
        ListNode* prev = fakehead;
        while(cur && cur->val < x) {
            prev = cur;
            cur = cur->next;
        };
        //cur: null or cur->val >= x
        
        //move all the nodes whose value is less than x before that node.
        if(cur == NULL || cur->next == NULL)
            return fakehead->next;
        ListNode* tomove = cur;
        ListNode* prev_tomove = cur;
        while(tomove && tomove->val >= x) { //find the first node to move.
            prev_tomove = tomove;
            tomove = tomove->next;
        }   

        while(tomove) {
            prev_tomove->next = tomove->next; //move the node.
            prev->next = tomove;
            prev = tomove;
            tomove->next = cur;

            tomove = prev_tomove->next; //to find the next tomove.
            while(tomove && tomove->val >= x) {
                prev_tomove = tomove;
                tomove = tomove->next;
            }
        }
        return fakehead->next;

    }
};