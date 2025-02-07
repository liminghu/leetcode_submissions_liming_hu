// https://leetcode.com/problems/swap-nodes-in-pairs

/*
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(head==nullptr || head->next == nullptr ) return head;
      ListNode dummyHead(0);
      dummyHead.next = head;
      
      ListNode *ex1;
      ListNode *ex2;
      ListNode *ex2Next;
      
      ListNode *ex1Pre = &dummyHead;
      ex1 = ex1Pre->next;
      ex2 = ex1->next;
      ex2Next = ex2->next;
     
      
      while(ex1 != nullptr && ex2 != nullptr) {
          ex1Pre ->next = ex2;
          ex2->next = ex1;
          ex1->next = ex2Next;
          
          ex1Pre = ex1Pre->next->next;
          ex1 = ex2Next;          
          if(ex1) {
              ex2= ex1->next;
              if(ex2) {
                  ex2Next = ex2->next;
              } else {
                  ex2Next = nullptr;
              };
          } else {
            ex2=nullptr;
            ex2Next = nullptr;  
          }
      };
        
      return dummyHead.next;
    };
};
