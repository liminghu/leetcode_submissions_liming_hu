// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

class Solution {
public:
//m product types of varying amounts, which are given as a 0-indexed integer array quantities, 
//where quantities[i] represents the number of products of the ith product type.
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        //A store can only be given at most one product type but can be given any amount of it.
        //After distribution, each store will have been given some number of products (possibly 0). 
        //Let x represent the maximum number of products given to any store. You want x to be as small 
        //as possible, i.e., you want to minimize the maximum number of products that are given to any store.
        int lo = 1, hi = INT_MAX/2;
        while(lo<hi) {
            int mid = lo+(hi-lo)/2;
            if(checkOK(quantities, n, mid))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
    bool checkOK(vector<int>& quantities, int n, int limit) {
        int count = 0;
        for(int x: quantities) {
            if(x%limit == 0)
                count += x/limit;
            else
                count += x/limit+1;
        }
        return count<=n;
    }
};