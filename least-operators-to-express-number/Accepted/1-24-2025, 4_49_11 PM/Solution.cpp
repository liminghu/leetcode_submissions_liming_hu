// https://leetcode.com/problems/least-operators-to-express-number

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {//2 <= x <= 100 1 <= target <= 2 * 10  8
        //x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is either addition, subtraction, multiplication, or division (+, -, *, or /).
        if(x>target) {
		// At this time, you can get target either by add target times x/x or subtract (x - target) times x/x to x
		// For example, x = 3, target = 2. Then, 3/3 + 3/3 or 3 - 3/3 is possible result
            return min(target*2-1, (x-target)*2);       
        }
        if(x==target)
            return 0;
        long long sums = x;
        int times = 0;
        while(sums<target) {// this is gready, put as much as possible 'x'
            times++;
            sums *= x;
        };
        if(sums==target) 
            return times;
		// when you have remainder, you have two choices, one is add, the other is subtract
		// for example, x = 3, target = 5. Then, 5 = 3 + 2 or 5 = 9 - 4
        int subtract = INT_MAX;
        int add = INT_MAX;
        if(sums-target < target) { // 9 - 5 = 4
            subtract = leastOpsExpressTarget(x, sums-target) + times; //using subtract
        }        
        add = leastOpsExpressTarget(x, target-(sums/x)) + times - 1; //using add
        return min(subtract, add)+1;  // No matter +/- used, one more operator is add
    }
};