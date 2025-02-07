// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
       ListNode* fakehead = new ListNode(0, head);
       ListNode* current = fakehead;
       int prefixSum = 0;
       unordered_map<int, ListNode*> mp;
       mp[0] = fakehead;

       while(current != nullptr) {
            prefixSum += current->val;
            mp[prefixSum] = current;
            current = current->next;
       };

       prefixSum = 0;
       current = fakehead;
       while(current!=nullptr) {
            if(current->val == 0) 
                current = current->next;
            prefixSum += current->val;
            current->next = mp[prefixSum]->next;
            current = current ->next;
       }
       return fakehead->next;

 
    /*    if(head == nullptr)
            return head;
        
        while(head != nullptr) {
            if(head->val == 0) {
                head = head->next;
                continue;
            };

            unordered_map<int, ListNode*> mp; //sum, pointer to the lowest node.
            int sum = 0;
            ListNode* cur = head;
            while(cur != nullptr) {
                sum += cur->val;
                // -3 3 0 0 5
                if(sum == 0) {
                    head = cur->next;
                    break;
                } else if(mp.find(sum)!=mp.end()) {
                    // 1 2 3 -3 4
                    // 1 3 6  3 7
                    ListNode* prev = mp[sum];
                    prev->next = cur->next;
                    break;
                } else {
                    mp[sum] = cur;
                };
                cur = cur->next;
            }
            if(cur == nullptr)
                return head;
        };
        return head;*/
    }
};