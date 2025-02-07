// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int ans=0;
        //Try to use two-pointers. Set one pointer to the left and one to the right of the array. Always move the pointer that points to the lower line.
        int i=0, j=n-1;
        int min_height = 0;
        while(i<j) {
            min_height = min(height[i], height[j]);
            water = (j-i)*min_height;
            if(water>ans)
                ans = water;
            if(height[i]<height[j])
                i++;
            else
                j--;
        };
        return ans;
        
    }
};