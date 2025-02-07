// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { //1 <= bloomDay[i] <= 109
        int n = bloomDay.size(); //n flowers
        if(m * k > n )
            return -1;
        int low = 1;
        int high = 1e9;
        while( low < high ) {    //Binary search.
            int mid = low + (high-low)/2;
            if(canMakeBougets(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
    bool canMakeBougets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            int count = 0;
            while(i<bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }
            if(count == k) {
                total++;
                i--;
            }
            if(total>=m)
                return true;
        }
        return false;
    }
};