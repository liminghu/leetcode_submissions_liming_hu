// https://leetcode.com/problems/can-place-flowers

/*
You have a long flowerbed in which some of the plots are planted, 
and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means 
empty and 1 means not empty, and an integer n, return true if n new flowers 
can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool ret;
        int sz = flowerbed.size();
        if(sz == 1)
            return flowerbed[0] == 0;

        for(int i=0; i<sz; i++) {
            if(flowerbed[i]==0) {
                if(i-1>=0 && i+1<sz && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                    n--;
                    flowerbed[i]=1;
                } else if(i==0 && i+1<sz && flowerbed[i+1]==0 ) {
                    n--;
                    flowerbed[i]=1;
                }else if(i==sz-1 && i-1>=0 && flowerbed[i-1]==0 ){
                    n--;
                    flowerbed[i]=1;
                }
                if(n==0)
                    return true;
            }
        }
        return false;
    }
};