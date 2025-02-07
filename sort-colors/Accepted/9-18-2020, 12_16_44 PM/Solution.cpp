// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int R = 0;
        int W = 0;
        int B = 0;
        for(int i=0; i<nums.size(); i++) {
            switch (nums[i]) {
            case 0: R++; break;
            case 1: W++; break;
            case 2: B++; break;
            default: 
                cout << "sth wrong! " << nums[i] << endl;
            }
        };
        for(int i=0; i<nums.size(); i++) {
            if (R > 0) {
                nums[i] = 0; R--;
            }
            else if (W>0) {
                nums[i] = 1; W--;
            } else if (B>0) {
                nums[i] = 2; B--;
            };
        }
        
    }
};