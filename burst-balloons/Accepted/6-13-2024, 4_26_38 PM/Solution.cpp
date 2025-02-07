// https://leetcode.com/problems/burst-balloons

class Solution {
public:
/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. 
You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
*/
//https://www.youtube.com/watch?v=z3hu2Be92UA
    int maxCoins(vector<int>& nums) { //1 <= n <= 300; 0 <= nums[i] <= 100
        int sz = nums.size();
        //padding
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        //mc[i][j]: maxCoins(nums[i..j]);
        vector<vector<int>> mc(sz+2, vector<int>(sz+2, 0));
        for(int l=1; l<=sz; l++) { //length
            for(int i=1; i<=sz-l+1; i++) {
                int j=i+l-1;
                for(int k=i; k<=j; k++) {
                    mc[i][j] = max(mc[i][j], mc[i][k-1]+mc[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
                }
            }
        };
        return mc[1][sz];
    }
};