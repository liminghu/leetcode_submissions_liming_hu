// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        //sorted in increasing order.
		ListNode dummyHead(0);
		dummyHead.next = head;
        
        ListNode *preloc = &dummyHead;
        ListNode *loc = head; 		
        ListNode *current = head->next;
        head->next = nullptr;
        while(current!=nullptr) {
            //from the head of the sorted list, find the corresponding location.
            loc = dummyHead.next; //search from head.
            while(loc != nullptr && current->val > loc->val) {
                preloc = loc;
                loc = loc->next;
            };
            //found.
            ListNode *temp;
			temp = current->next;
            
			preloc->next = current;
			current->next = loc;
             
                
			current = temp;
            preloc = &dummyHead;
            
        }
		
		return dummyHead.next;
    }
};