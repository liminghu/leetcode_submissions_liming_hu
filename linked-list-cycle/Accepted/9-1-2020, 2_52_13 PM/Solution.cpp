// https://leetcode.com/problems/linked-list-cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return false;
		
        
		ListNode *nextNext = head->next->next;
		while(head != nullptr && nextNext != nullptr && head != nextNext ) {
			if (nextNext->next != nullptr)
                nextNext = nextNext->next->next;
            else
                break;
			head = head->next;
		};
		
		if (head==nullptr || nextNext == nullptr || nextNext->next == nullptr) 
			return false;
		else
			return true;
    }
};