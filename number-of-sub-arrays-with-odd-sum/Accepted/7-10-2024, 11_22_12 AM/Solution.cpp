// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

/*
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.
*/

class Solution {
public:
 
    int numOfSubarrays(vector<int>& arr) { /* 1 <= arr.length <= 105
                                                1 <= arr[i] <= 100*/

        //all subarrays: 
        // odd sum.
        int odd = 0; //number of odd numbers.
        int even = 0; //number of even numbers.
        int answer = 0;
        int modulus = (int) 1e9 + 7;
        for( auto number:arr ) {
            if( number % 2 == 0 )  
            /*Firstly if a number is even then it would just increase even number of subarrays by 1 because the 
            number itself becomes the new subarray which is added in even total. Even + Even = Even 
            The odd sum subarrays remain constant as the sum still remains constant. Odd+Even=Odd*/
                even ++; //number of even numbers.
            else { //odd.
                swap( odd, even );//Odd + Odd = Even; Even + Odd = Odd;
                odd ++;  //number of odd numbers.
            }
            answer = ( answer  + odd ) % modulus; //if all are odd numbers: 1+2+3+4+...
        }
        return answer;
    }


};