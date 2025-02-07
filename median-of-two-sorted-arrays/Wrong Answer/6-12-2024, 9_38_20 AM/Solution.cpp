// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int m_index = (m+n)%2==0? (m+n)/2-1: (m+n)/2; //even: (m+n)/2-1, (m+n)/2 mean.
        int n1_index = 0;
        int n2_index = 0;
        int count = 0;
        double ans;
        while( n1_index < m & n2_index < n ) {
            if(count == m_index)
                break;
            if(nums1[n1_index] < nums2[n2_index]) {
                n1_index++;
            } else {
                n2_index++;
            }
            count++;
        };
        if(n1_index == m) {
            while( n2_index < n ) {
                if(count == m_index)
                    break;
                n2_index++;
                count++;
            };
        }
        if(n2_index == n) {
            while( n1_index < m ) {
                if(count == m_index)
                    break;
                n1_index++;
                count++;
            };
        }

        if((m+n)%2==0) { //even
            if(n1_index < m  && n2_index < n) {
                return float(nums1[n1_index]+nums2[n2_index])/2;
            } else if (n1_index == m) {
                return float(nums2[n2_index]+nums2[n2_index+1])/2;
            } else {
                return float(nums1[n1_index]+nums1[n1_index+1])/2;
            }

        } else {
            if( n1_index < m  && n2_index < n ) {
                if ( nums1[n1_index] < nums2[n2_index] )
                    return nums1[n1_index];
                else
                    return nums2[n2_index];
            } else if (n1_index == m) {
                return nums2[n2_index];
            } else {
                return nums1[n1_index];
            }

        }
        
    }
};