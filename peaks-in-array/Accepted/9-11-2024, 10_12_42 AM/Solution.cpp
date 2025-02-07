// https://leetcode.com/problems/peaks-in-array

/*
A peak in an array arr is an element that is greater than its previous and next element in arr.
You are given an integer array nums and a 2D integer array queries.
You have to process queries of two types:
queries[i] = [1, li, ri], determine the count of peak elements in the 
subarray
 nums[li..ri].
queries[i] = [2, indexi, vali], change nums[indexi] to vali.
Return an array answer containing the results of the queries of the first type in order.
Notes:
The first and the last element of an array or a subarray cannot be a peak.
3 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i][0] == 1 or queries[i][0] == 2
For all i that:
queries[i][0] == 1: 0 <= queries[i][1] <= queries[i][2] <= nums.length - 1
queries[i][0] == 2: 0 <= queries[i][1] <= nums.length - 1, 1 <= queries[i][2] <= 105
*/
using LL = long long;
class SegTreeNode {
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info;  // the sum value over the range
    bool lazy_tag; 
    LL lazy_val;
        
    SegTreeNode(int a, int b, int val) {  // init for range [a,b] with val                
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a == b) {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left == NULL) {
            left  = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }    
    
    SegTreeNode(int a, int b, vector<int>& val) { // init for range [a,b] with the same-size array val                
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a == b) {
            info = val[a];
            return;
        }        
        int mid = (a+b)/2;
        if (left == NULL) {
            left  = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }    
    
    void pushDown() {
        if (lazy_tag == 1 && left) {
            left->info  = lazy_val * ( left->end - left->start + 1);
            right->info = lazy_val * (right->end - right->start + 1);
            left->lazy_tag = 1; 
            left->lazy_val = lazy_val;
            right->lazy_tag = 1; 
            right->lazy_val = lazy_val;
            lazy_tag = 0;  
            lazy_val = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val) {    // set range [a,b] with val        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <= b ) { // completely covered within [a,b]
            info = val * ( end - start + 1 );
            lazy_tag = 1;
            lazy_val = val;
            return;
        }

        if (left) {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b) {     // query the sum over range [a,b]   
        if (b < start || a > end ) 
            return 0;  // check with your own logic

        if (a <= start && end <=b) 
            return info;  // check with your own logic
        
        
        if (left) {
            pushDown();     
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);        
            info = left->info + right->info;    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>peaks(n, 0);
        for (int i=1; i<n-1; i++) { //exclude left, right.
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1])
                peaks[i] = 1;
        }
        
        SegTreeNode* root = new SegTreeNode(0, n-1, peaks); 
        
        vector<int> rets;
        for (auto query: queries) {
            if (query[0] == 1 ) { //queries[i] = [1, li, ri], determine the count of peak elements in the subarray nums[li..ri].
                int a = query[1], b = query[2];                
                rets.push_back(root->queryRange(a+1, b-1));                
            } else { //queries[i] = [2, indexi, vali], change nums[indexi] to vali.
                int indexi = query[1];
                nums[indexi] = query[2];
                if (indexi>=1 && indexi<n-1) 
                    check(root, indexi, nums, peaks);
                if (indexi-1>=1 && indexi-1<n-1) 
                    check(root, indexi-1, nums, peaks);
                if (indexi+1>=1 && indexi+1<n-1) 
                    check(root, indexi+1, nums, peaks);                
            }                
        }
        
        return rets;      
    }

    void check(SegTreeNode* root, int i, vector<int>& nums, vector<int>& peaks)
    {
        int v = nums[i]>nums[i-1] && nums[i]>nums[i+1];
        if (v==peaks[i]) 
            return;
        peaks[i] = v;
        root->updateRange(i, i, v );
    }
};