// https://leetcode.com/problems/merge-k-sorted-lists

//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            k == lists.length
            0 <= k <= 104
            0 <= lists[i].length <= 500
            -104 <= lists[i][j] <= 104
            lists[i] is sorted in ascending order.
            The sum of lists[i].length will not exceed 104.
        */
        auto cmp = [](const ListNode* first, const ListNode* second) {
            return first->val > second->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq; //min queue
        int k = lists.size();
        if(k<=0)
            return NULL;
        for(int i=0; i<k; i++) {
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* prev = head; 
        while(!pq.empty()) {
            ListNode* t = pq.top();
            if(!t)
                continue;
            pq.pop();
            if(t->next)
                pq.push(t->next);
            prev = cur;
            cur = t;
            prev->next = cur;
        }
        return head->next;
    }
};