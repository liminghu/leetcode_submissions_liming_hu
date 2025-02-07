// https://leetcode.com/problems/reverse-linked-list-ii

/*
Given the head of a singly linked list and two integers left and right where 
left <= right, reverse the nodes of the list from position left to position right, 
and return the reversed list.
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)
            return head;
        if(left == right)
            return head;
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        int count = 1;
        ListNode* preleft = NULL;
        while(count < left && leftNode) {
            count++;
            preleft = leftNode;
            leftNode = leftNode->next;
        }
        if(count < left)
            return head;
        count = 1;
       while(count < right && rightNode) {
            count++;
            rightNode = rightNode->next;
        }
        if(count < right)
            return head;
        ListNode* afterright = rightNode->next;

        rightNode->next = NULL; //break the link.
        
        //reverse left to right.
        ListNode* last = NULL;
        ListNode* cur = leftNode;
        ListNode* nxt;
        while(cur) {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }
        //return last.
        if(preleft == NULL)
            head = last;
        else
            preleft->next = last;

        cur = head;
        while(cur->next)
            cur = cur->next;
        cur->next = afterright;
        return head;
    }
};