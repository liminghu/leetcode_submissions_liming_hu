// https://leetcode.com/problems/h-index-ii

class Solution {
public:
    int hIndex(vector<int>& citations) { //sorted in ascending order.
        int n = citations.size();

        int mid = n/2;
        int low = 0;
        int high = n-1;

        while ( low <= high) {
            mid = low + (high-low)/2;

            if(citations[mid] == n - mid)
                return citations[mid];
            else if(citations[mid] < n - mid) {
                low = mid+1;
            } else
                high = mid-1;
        }

        return n-low;


    }
};