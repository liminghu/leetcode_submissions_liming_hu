// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mp;
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;    
        while(cur) {
            mp[cur->val]++;
            cur = cur->next;
        };

        ListNode* fakehead = new ListNode(0, head);
        cur = head;
        ListNode* prev = fakehead;
        while(cur) {
            int val = cur->val;
            int count = mp[val];
            if(count > 1) {
                //delete all the nodes whose val is cur->val.
                while(cur && cur->val == val)
                    cur = cur->next;
                prev->next = cur;
            } else {
                prev = cur;
                cur = cur->next;
            };
        }
        return fakehead->next;       
    }
};