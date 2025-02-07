// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    /*int findKthPositive0(vector<int>& arr, int k) {
        int left = 1;
        int right = arr.back()+k;
        while( left < right ) {
            int mid = right-(right-left)/2;
            int M = mid-1;
            int T = lower_bound(arr.begin(), arr.end(), mid)-arr.begin();
            int missing = M-T;
            if(missing<=k-1)
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }*/
    /*int findKthPositive2(vector<int>& arr, int k) {
        int kthMissingNum = k; //if the array is empty it will be k.
        for(int num: arr) { //sorted.
            if( num <= kthMissingNum) //This step accounts for the missing positive integers. If the number is less than or equal to k, 
                          //it means we've encountered an actual element of the sequence, so the k-th missing positive integer is 
                          //pushed further by one.
                kthMissingNum++;
            else   //This happens because there’s no need to continue iterating once we’ve passed the range where the k-th missing integer could exist.
                break;
        }
        return kthMissingNum;
    }*/
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size()-1;
        while(left<=right) {
            int pivot = left+(right-left)/2;
            int missing_num = arr[pivot]-(pivot+1);
            if(missing_num<k)
                left = pivot +1;
            else
                right = pivot-1;
        };
        //left = right+1;
        /*At the end of the loop, left = right + 1, and the kth missing number is in-between arr[right] and arr[left]. 
        The number of integers missing before arr[right] is arr[right] - right - 1. Hence, 
        the number to return is arr[right] + k - (arr[right] - right - 1) = k + left.
        */
        int missingBefore = arr[right] - right - 1;
        return arr[right] + (k - missingBefore); 
    }
};