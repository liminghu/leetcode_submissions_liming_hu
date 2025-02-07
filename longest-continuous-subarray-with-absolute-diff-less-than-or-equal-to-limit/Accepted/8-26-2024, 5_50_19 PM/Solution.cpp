// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that 
the absolute difference between any two elements of this subarray is less than or equal to limit.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         deque<int> qmax({0});
         deque<int> qmin({0});         
        int ret = 0;        
        int j = 0;
        int mx = nums[0];
        int mn = nums[0];

        for(int i=0; i<nums.size(); i++) {
            while(mx-mn <=limit) {
                ret = max(ret, j-i+1);
                j++;
                if(j==nums.size())
                    break;

                while(qmax.size()>0 && nums[j] >=nums[qmax.back()])
                    qmax.pop_back();
                qmax.push_back(j);
                mx = nums[qmax.front()];

                while(qmin.size()>0 && nums[j] <=nums[qmin.back()])
                    qmin.pop_back();
                qmin.push_back(j);
                mn = nums[qmin.front()];                
            }
            if(j==nums.size())
                break;
            //set.erase(set.find(nums[i]));
            if(qmax.size()>0 && qmax.front() == i) {
                qmax.pop_front();
                if(qmax.size()>0)
                    mx = nums[qmax.front()];
            }
            if(qmin.size()>0 && qmin.front() == i) {
                qmin.pop_front();
                if(qmin.size()>0)
                    mn = nums[qmin.front()];
            }
        }
        return ret;
 
 /*       multiset<int> set({nums[0]}); //sorted nondecreasing.
        int ret = 0;
        
        int j = 0;
        for(int i=0; i<nums.size(); i++) {
            while(*set.rbegin()-*set.begin() <=limit) {
                ret = max(ret, j-i+1);
                j++;
                if(j<nums.size())
                    set.insert(nums[j]);
                else
                    break;
            }
            if(j==nums.size())
                break;
            set.erase(set.find(nums[i]));
        }
        return ret;*/
    }
};