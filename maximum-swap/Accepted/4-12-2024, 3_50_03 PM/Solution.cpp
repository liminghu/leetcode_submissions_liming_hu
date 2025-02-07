// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) { //assume non negative int.   2736
        string num_s = to_string(num); //number to string:    2 7  3 6 /n
        int n = num_s.size();
        int maxPos =  n - 1;
        int bestSrc = -1, bestDest = -1;

        for(int i=n-1; i>=0; i--) {
            if(num_s[i]> num_s[maxPos])
                maxPos = i;
            else if (num_s[i] < num_s[maxPos]) {
                bestSrc = maxPos;
                bestDest = i;
            }
        }

        if(bestSrc != -1 )
            swap(num_s[bestSrc], num_s[bestDest]);

        return stoi(num_s);

    }
};