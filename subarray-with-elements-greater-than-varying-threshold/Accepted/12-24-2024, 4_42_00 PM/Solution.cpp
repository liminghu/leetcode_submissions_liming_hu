// https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {//1 <= nums[i], threshold <= 109
        //The gist of the above statement is that we need to find the subarray minimum and we need to expand that subarray as max as possible so as to have as less threshold / k as possible.
        int n = nums.size();
        vector<int> stk; //stack.
        vector<int> nextS(n, -1); //next smaller element
        vector<int> prevS(n, -1); //prev smaller element.
        for(int i=0; i<n; i++) { //find the next smaller element.
            while(!stk.empty() && nums[i] < nums[stk.back()]) {
                nextS[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        };
        stk.clear();
        for(int i=n-1; i>=0; i--) { //find the prev smaller element.
            while(!stk.empty() && nums[i] < nums[stk.back()]) {
                prevS[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        };        
       for(int i=0; i<n; i++) { 
            int left = prevS[i];
            int right = nextS[i]==-1? n: nextS[i];
            int len = right-left-1;     //len of subarray formed with a[i] as minimum.
            if(nums[i]> threshold /(double)len)
                return len;
       }        
       return -1;
    }
};