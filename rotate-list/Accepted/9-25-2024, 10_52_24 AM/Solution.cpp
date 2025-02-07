// https://leetcode.com/problems/rotate-list

//Given the head of a linked list, rotate the list to the right by k places.
/*
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0)
            return head;
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* tail = head;
        int nodecount = 1;
        while( tail->next ) {
            nodecount++;
            tail = tail->next;
        };
        //cout << "nodecount: " << nodecount << endl;
        tail->next = head;
        k = k % nodecount;
        while( k > 0 ) {
            k--;
            head = tail;
            int j=1;
            while(j<nodecount) { 
                tail = tail->next;
                j++;
            }
        };
        tail->next = NULL;
        return head;    
    }
};