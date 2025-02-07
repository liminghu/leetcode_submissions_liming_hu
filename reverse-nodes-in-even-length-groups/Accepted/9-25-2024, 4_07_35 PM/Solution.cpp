// https://leetcode.com/problems/reverse-nodes-in-even-length-groups

/*
You are given the head of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural 
numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,

The 1st node is assigned to the first group.
The 2nd and the 3rd nodes are assigned to the second group.
The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

Reverse the nodes in each group with an even length, and return the head of the modified linked list.
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 105
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*> heads;
        vector<int> lens;

        ListNode* p = head;
        int len = 1;
        while(1) {
            heads.push_back(p);
            int count = 1;
            for(int i=0; i<len-1; i++) {
                if(p->next == NULL)
                    break;
                p = p->next;
                count++;
            };
            lens.push_back(count);
            if(p->next == NULL)
                break;
            
            ListNode* temp = p->next; 
            p->next = NULL; //break the list.
            p = temp;
            len++;
        };

        for(int i=0; i<heads.size(); i++) {
           if(lens[i] % 2 == 0)
                heads[i] = reverseLinkedList(heads[i]);
        };
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
 