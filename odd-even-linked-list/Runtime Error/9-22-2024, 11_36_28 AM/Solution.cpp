// https://leetcode.com/problems/odd-even-linked-list

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by 
the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        if(head->next->next== NULL)
            return head;

        ListNode* oddhead = head;
        ListNode* evenhead = head->next;

        ListNode* curodd = oddhead;
        ListNode* cureven = evenhead;

        while(curodd != NULL && cureven != NULL) {
               curodd->next = cureven->next;
               curodd = curodd->next;
               cureven->next = curodd->next;
               cureven = cureven->next;
        }
        curodd->next = evenhead;
        return head;
    }
};