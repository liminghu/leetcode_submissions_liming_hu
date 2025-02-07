// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1==nullptr) return l2;
      if (l2==nullptr) return l1;
      
      ListNode dummyHead(0);
      ListNode* tail = &dummyHead;
      while(l1!=nullptr && l2!=nullptr) {
        if(l1->val <=l2->val) {
			tail->next = l1;
			l1= l1->next;
		} else {
			tail -> next = l2;
			l2= l2->next;
        };
        tail = tail->next;        
      }
        
      if(l1==nullptr)
          tail->next = l2;
      else
          tail->next = l1;
        
      return dummyHead.next;
    }
};