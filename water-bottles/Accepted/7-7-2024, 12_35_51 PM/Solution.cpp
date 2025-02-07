// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if( numBottles < numExchange )
            return numBottles;
        
        int fullBottle = numBottles;
        int empty_bottle = 0;
        int total = fullBottle + empty_bottle;
        int result = 0;
        
        while(total >= numExchange ) { // 15+0 > 4
            result += fullBottle;   //15
            empty_bottle = total % numExchange;   // 15%4 = 3
            fullBottle = total / numExchange; //  
            total = fullBottle+empty_bottle; 
        } 

        return result+fullBottle;
        
    }
};