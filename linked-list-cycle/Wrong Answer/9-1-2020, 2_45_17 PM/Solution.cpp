// https://leetcode.com/problems/linked-list-cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return false;
		
        
		ListNode *nextNext = head->next->next;
		while(head != nullptr && nextNext != nullptr && head != nextNext ) {
			nextNext = nextNext->next->next;
			head = head->next;
		};
		
		if (head==nullptr) 
			return false;
		else
			return true;
    }
};