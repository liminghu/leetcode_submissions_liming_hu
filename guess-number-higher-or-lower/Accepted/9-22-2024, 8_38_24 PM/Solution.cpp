// https://leetcode.com/problems/guess-number-higher-or-lower

/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
1 <= n <= 231 - 1
1 <= pick <= n
*/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //-1: Your guess is higher than the number I picked (i.e. num > pick).
        //1: Your guess is lower than the number I picked (i.e. num < pick).
        //0: your guess is equal to the number I picked (i.e. num == pick).
        int low = 1;
        int high = n;
        int num = low+(high-low+1)/2;
        while(low<high) {
            if( guess(num) == -1) {
                high = num - 1;
            } else if(guess(num)== 1) {
                low = num + 1;
            } else 
                break;
            num = low+(high-low+1)/2;
        }

        return low<high? num: low;
    }
};