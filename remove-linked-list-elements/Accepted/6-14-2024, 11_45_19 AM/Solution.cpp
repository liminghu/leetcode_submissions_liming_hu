// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*  dummyhead = new ListNode(0, head);
        //dummyhead->next = head;

        ListNode* cur =  dummyhead;
        ListNode* next = head;
        while(next!=nullptr) {
            if(next->val == val) {
                //remove the next node.
                cur->next = next->next;                
                next = cur->next;
            } else {
                cur = cur->next;
                if(cur !=nullptr)
                    next = cur->next;
                else
                    next = nullptr;
            }
        }

        return dummyhead->next;
        
    }
};