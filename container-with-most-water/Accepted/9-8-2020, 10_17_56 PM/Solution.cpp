// https://leetcode.com/problems/container-with-most-water


class Solution {
public:
    int maxArea(vector<int>& height) {
        //two pointers.
		int l=0;
		int r = height.size()-1; //the widest container.
		int area = min(height[l], height[r]) *(r-l);
		while(l<r) {
			area = max(area, min(height[l], height[r]) *(r-l));
			if(height[l] < height[r]) 
				l++;
			else 
				r--;
		};
		return area;
    }
};