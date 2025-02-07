// https://leetcode.com/problems/spiral-matrix-iv

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {//You are also given the head of a linked list of integers.
        vector<vector<int>> res(m, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int cur_d = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        for(; head!=NULL; head=head->next) {
            res[i][j] = head->val;
            int newi= i+dirs[cur_d][0];
            int newj = j+dirs[cur_d][1];
            if(newi<0 || newj<0 || newi>=m || newj >=n || res[newi][newj]!=-1)
                cur_d = (cur_d+1)%4;
            i+= dirs[cur_d][0];
            j+= dirs[cur_d][1];
        };
        return res;
    }
};