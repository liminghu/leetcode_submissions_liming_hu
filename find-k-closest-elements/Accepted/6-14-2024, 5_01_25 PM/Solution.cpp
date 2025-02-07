// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

*/

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*int sz = arr.size();
        for(int i=0; i<sz; i++)
            arr[i] = arr[i]-x;
        priority_queue<int, vector<int>, decltype([](int first, int second){ return (abs(first) < abs(second)) || (abs(first) == abs(second) && first < second ); })
            > kClosest; //max at the top.

        for(int i=0; i<sz; i++) {
            kClosest.push(arr[i]); 
        };

        while(kClosest.size()>k) 
            kClosest.pop();
        
        vector<int> ans;
        while(!kClosest.empty()) {
            ans.push_back(kClosest.top()+x);
            kClosest.pop();
        } ;

        sort(ans.begin(), ans.end());
        return ans;*/

        int sz = arr.size();
        //initialize binary search bounds.
        int left = 0;
        int right = sz - k;

        //binary search.
        while(left <right) {
            int mid = (left+right)/2;
            if(x-arr[mid]>arr[mid+k]-x) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        vector<int> ans;
        for(int i=left; i<left+k; i++) 
        ans.push_back(arr[i]);

        return ans;
        
    }
};