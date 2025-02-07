// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

/*
A critical point in a linked list is defined as either a local maxima or a local minima.
A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the
 minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two 
 distinct critical points. If there are fewer than two critical points, return [-1, -1].
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //[minDistance, maxDistance] 
        //1. find all the critical points. and the corresponding distance.
        vector<int> distance(2, -1);
        ListNode* cur;
        ListNode* prev;
        ListNode* next;
        
        if(head == nullptr)
            return distance;
        prev = head;
        cur = head->next;
        if(cur == nullptr)
            return distance;
        next = cur->next;

        vector<pair<ListNode*, int>> criticalpoints;
        int between = 0;
        while(next != nullptr) {
            if( cur->val > next->val && cur->val > prev->val || 
                cur->val < next->val && cur->val < prev->val ) {
                criticalpoints.push_back({cur, between+1}); 
                between = 0;
            } else {
                between++;
            }

            prev = cur;
            cur = cur->next;
            next = next->next;
        }
        if(criticalpoints.size() > 0)
            criticalpoints[0].second = -1; //first critical node.

        if(criticalpoints.size() <2)
            return distance;
        
        distance[0] = INT_MAX;
        distance[1] = 0;
        for(int i=1; i<criticalpoints.size(); i++) {
            distance[0] = min(distance[0], criticalpoints[i].second);
            distance[1] += criticalpoints[i].second;
        }
        return distance;
    }
};