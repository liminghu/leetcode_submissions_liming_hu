// https://leetcode.com/problems/remove-nodes-from-linked-list

/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.
The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> st;
        while(cur != NULL) {
            st.push(cur);
            cur = cur->next;
        }

        cur = st.top();
        st.pop();
        int max_val = cur->val;
        ListNode* res = new ListNode(max_val);

        while(!st.empty()) {
            cur = st.top();
            st.pop();
            if(cur->val < max_val)
                continue;  //this node is ignored.
            else {
                ListNode* newnode = new ListNode(cur->val);
                newnode->next = res;
                res = newnode;
                max_val = cur->val;
            };
        }
        return res;
    }
};