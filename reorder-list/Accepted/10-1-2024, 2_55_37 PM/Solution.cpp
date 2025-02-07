// https://leetcode.com/problems/reorder-list

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {
        //L0 → L1 → … → Ln - 1 → Ln
        //L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
        if(head==NULL || head->next==NULL)
            return;
        //at least two nodes.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        //slow->next: point to the head of the second half.
        ListNode* secondhalf = reverse(slow->next);
        slow->next = NULL; //cut the second half.
        
        ListNode* first = head;

        //merge
        while(secondhalf) {
            ListNode* t1 = first->next;
            ListNode* t2 = secondhalf->next;
            first->next = secondhalf;
            secondhalf->next = t1;
            first = t1;
            secondhalf = t2;
        };
    }

    ListNode* reverse(ListNode* head) {
        ListNode* last = NULL;
        ListNode* cur = head;
        ListNode* nxt;
        while(cur) {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        };
        return last;
    }
};