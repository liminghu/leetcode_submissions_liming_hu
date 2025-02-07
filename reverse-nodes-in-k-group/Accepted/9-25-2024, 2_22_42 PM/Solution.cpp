// https://leetcode.com/problems/reverse-nodes-in-k-group

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return 
the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If 
the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> heads;
        ListNode* p = head;
        int flag = 1;
        while(p) {
            heads.push_back(p);
            for(int i=0; i<k-1; i++) {
                if(p->next)
                    p = p->next;
                else
                    flag = 0; //there is a list has less than k nodes.
            };
            
            ListNode* temp = p->next; //if flag ==0, no next.
            p->next = NULL; //break the list.
            p = temp;
        };

        for(int i=0; i<heads.size(); i++) {
            if(i==heads.size()-1 && flag == 0)
                continue;
            heads[i] = reverseLinkedList(heads[i]);
        }
        for(int i=0; i<heads.size()-1; i++) {
            ListNode* h = heads[i];
            while(h->next)
                h = h->next;
            h->next = heads[i+1];
        }
        return heads[0];
    }

    ListNode* reverseLinkedList(ListNode*  head) {
        ListNode* last = NULL; //the head of reversed list.
        ListNode* cur = head;
        ListNode* nxt;
        
        while(cur) { //from head to end, add head to last (as stack.)
            nxt = cur->next;
            cur->next = last; //as stack.
            last = cur; //update last.
            cur = nxt; //next node.
        }
        return last;
    }
};