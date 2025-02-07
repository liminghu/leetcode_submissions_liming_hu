// https://leetcode.com/problems/merge-nodes-in-between-zeros

/*You are given the head of a linked list, which contains a series of integers separated by 0's. 
The beginning and end of the linked list will have Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose 
value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.
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
    ListNode* mergeNodes(ListNode* head) {
        /*
            The number of nodes in the list is in the range [3, 2 * 105].
            0 <= Node.val <= 1000
            There are no two consecutive nodes with Node.val == 0.
            The beginning and end of the linked list have Node.val == 0.
        */
        ListNode* prev;
        ListNode* cur;
        ListNode* next;
        prev = head;
        cur = prev->next;
        next = cur->next;
       
        while( next!= nullptr ) {
            prev->val = cur->val;
            while( next!=nullptr && next->val != 0 ) {
                prev->val = prev->val + next->val;
                cur = cur->next;
                next = cur->next;
                prev->next = cur;
            }
            if(next->val == 0 && next->next == nullptr) {
                prev->next = nullptr;
                break;
            };

            prev->next = next;
            prev = next;
            cur = prev->next;
            next = cur->next;
        }

        return head;

    }
};