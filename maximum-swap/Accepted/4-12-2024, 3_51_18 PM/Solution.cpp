// https://leetcode.com/problems/maximum-swap

/*思路：从右 to left，update maxIndex,同时找leftMost最小的数字去交换
怎么想出这个算法的？
1.	观察规律
	17772
77712
1.	选两个位置的数字交换，选一个高位的小数字，和一个低位的大数字，交换后，整体会变大
2.	要求一次交换最大？选最低位的大数字，和一个最高位的小数字交换
 2. 大概形成思路思路：
	算法要从右到左，找低位的大数字，并且要找最大的数字
找leftmost的高位数字，小于大数字，就交换
1.	Propose 算法和数据结构：
	rightMax，从右到左更新
3. Edge Case Coverage：
	不需要交换怎么办？没找到大数字和小数字交换

*/
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