// https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k

//class Solution {
//public:
/*
Given an array of integers nums and an integer k, return the number of 
subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 */
/*    long long countSubarrays(vector<int>& nums, int k) { //1 <= nums.length <= 105, 0 <= nums[i], k <= 109
        int sz = nums.size();
        //the number of subarrays of nums ending with ith element where the bitwise AND of the elements of the subarray equals k
        
    }
};*/

class Solution {
public:
    
    int solve(vector <int> &count,int i,int j){
        int num = 0;
        for(int k=0;k<32;k++){
            if((i-j+1)==count[k]) 
                num = num|(1<<k);
        }
        return num;
    }
    long long findSol(vector <int> &nums,int tar){
         vector <int> count(32,0);
        int j = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int k=0;k<32;k++){
                if(nums[i]&(1<<k)) count[k]+=1;
            }
            
            while(j<=i && solve(count,i,j)<tar ){
                for(int k=0;k<32;k++){
                if(nums[j]&(1<<k)) count[k]-=1;
            }
                j+=1;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int tar) {
       
        return findSol(nums,tar)-findSol(nums,tar+1);

    }
};