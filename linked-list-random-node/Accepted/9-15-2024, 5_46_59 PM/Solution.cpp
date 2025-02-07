// https://leetcode.com/problems/linked-list-random-node

/*
Given a singly linked list, return a random node's value from the linked list. Each node must 
have the same probability of being chosen.
Implement the Solution class:
Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of 
the list should be equally likely to be chosen.
The number of nodes in the linked list will be in the range [1, 104].
-104 <= Node.val <= 104
At most 104 calls will be made to getRandom.
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
private:
    int numNodes_;
    ListNode* head_;
public:
    Solution(ListNode* head) {
        head_ = head;
        ListNode* cur = head_;
        int count = 0;
        while(cur != NULL) {
            count++;
            cur = cur->next;
        };
        numNodes_ = count;
    }
    
    int getRandom() {
        int r = rand() % numNodes_;
        ListNode* cur  = head_;
        while(r>0) {
            cur = cur->next;
            r--;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */