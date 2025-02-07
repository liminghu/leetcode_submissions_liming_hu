// https://leetcode.com/problems/wiggle-sort-ii

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        
        int mid = (nums.size()-1)/2;
        int end = nums.size()-1;
        for(int i=0; i<nums.size(); i++) {
            if( i%2 == 0) {
                nums[i] = sorted[mid]; //less      less
                mid--;
            } else {
                nums[i] = sorted[end];  //     more      more  
                end--;
            }
            
            
        }
    }
};