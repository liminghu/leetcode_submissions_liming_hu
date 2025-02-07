// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

/**
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing 
all nodes from the linked list that have a value that exists in nums.
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set;
        for(int i=0; i<nums.size(); i++) {
            set.insert(nums[i]);
        };

        ListNode* fake_head = new ListNode(0, head);
        ListNode* cur = head;
        ListNode* prev = fake_head;
        while(cur != nullptr) {
            if(set.find(cur->val)!= set.end()) { //found
                cur = cur->next;
                prev->next = cur;
            } else {
                prev = cur;
                cur = cur->next;
            };
        }

        return fake_head->next;
        
    }
};