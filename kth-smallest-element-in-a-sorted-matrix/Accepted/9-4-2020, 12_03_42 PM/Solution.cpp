// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	int left = matrix[0][0];
		int right = matrix.back().back();
		while(left <right) {
			int mid = left + (right-left)/2;
			int cnt = 0;
			for (int i=0; i<matrix.size(); i++) { // for all rows.
				cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); 
			};
			if(cnt<k) 
				left = mid+1;
			else 
				right = mid;
		}
		
		return left;
    }
};