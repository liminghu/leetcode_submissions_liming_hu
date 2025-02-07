// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q; //maximum priority queue, the maximum element is at the top.
		for (int i=0; i<matrix.size(); i++) { //rows
			for (int j=0; j<matrix[i].size(); i++) { //columns
				q.emplace(matrix[i][j]);
				if(q.size()>k) q.pop();
			}
		}
		
		return q.top();
    }
};