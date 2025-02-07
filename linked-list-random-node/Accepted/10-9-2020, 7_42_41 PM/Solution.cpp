// https://leetcode.com/problems/linked-list-random-node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_= head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
         int winner = head_->val;
        ListNode* cur = head_;
        for(int i=1; cur->next!=nullptr; i++) {
            cur = cur->next;
            if(rand()%(i+1) == i) {
                winner = cur->val;
            }
        };
        return winner;  
    }
private:
   ListNode* head_; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */