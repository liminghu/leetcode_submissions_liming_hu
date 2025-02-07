// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element
 to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's 
present in the array together at any location.
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        /*  1 <= nums.length <= 105
            nums[i] is either 0 or 1.*/
        int sz = nums.size();
        int num1Total = 0;  //window size.
        for(int i=0; i<sz; i++) {
            if(nums[i]==1)
                num1Total++;
        }
        //cout << "num1Total = " << num1Total << endl;
        if(num1Total<=1 || num1Total >=sz-1)
            return 0;

        vector<int> new_nums(2*sz, 0);
        for(int i=0; i<sz; i++) {
            new_nums[i] = nums[i];
            new_nums[i+sz] = nums[i];
        };

        //slide window: start from i     i+num1Total-1;
        int minSwap = INT_MAX;
        int num0CurWin = 0;
        for(int j=0; j<num1Total; j++) {
                if(new_nums[j] == 0)
                    num0CurWin++;
        };
        //cout << "num0CurWin = " << num0CurWin << endl;
        for(int i=1; i<sz; i++) {           
            num0CurWin = num0CurWin + int(new_nums[i+num1Total-1] == 0) - int(new_nums[i-1] == 0);
            //cout << "num0CurWin = " << num0CurWin << endl;
            minSwap = min(minSwap, num0CurWin);
        };
        return minSwap;
    }
};