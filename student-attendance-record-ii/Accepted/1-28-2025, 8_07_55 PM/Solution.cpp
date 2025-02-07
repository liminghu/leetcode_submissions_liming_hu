// https://leetcode.com/problems/student-attendance-record-ii

class Solution {
    int M = 1e9+7;
public:
    int checkRecord(int n) { //1 <= n <= 1e5
        //absent, late, or present 
        //attendance award:
        //The student was absent ('A') for strictly fewer than 2 days total.
        //The student was never late ('L') for 3 or more consecutive days
        //Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
        /*As the attendance records is made by 3 characters ('P', 'L', 'A'), the total number can be divided into
            Total = ended with P + ended with L + ended with A.
            If we define following series
            T(n) is the total number of all possible attendance records with length n.
            P(n) is the total number of all possible attendance records ended with 'P' with length n.
            L(n) is the total number of all possible attendance records ended with 'L' with length n.
            A(n) is the total number of all possible attendance records ended with 'A' with length n.
            It can be inferred that
            T(n) = A(n) + P(n) + L(n), n ≥ 1.
        */
        if(n==1)
            return 3;
        vector<int> A(n+1, 0);
        vector<int> P(n+1, 0);
        vector<int> L(n+1, 0);
        P[0] = 1;
        L[0] = 1;
        A[0] = 1;

        L[1] = 3;
        A[1] = P[0]+L[0]; //2
        P[1] = 3;

        A[2] = 4;  //(P, L) * (P, L)


        for(int i=1; i<n; i++) {
            A[i-1] %= M;
            P[i-1] %= M;
            L[i-1] %= M;
            //present
            P[i] = ( (A[i-1] +P[i-1])%M + L[i-1] ) % M;
            
            if(i>1) //The student was never late ('L') for 3 or more consecutive days
                L[i] = ( (A[i-1]+P[i-1])%M + (A[i-2]+P[i-2])%M )%M;
            
            if(i>2) //The student was absent ('A') for strictly fewer than 2 days total.
                A[i] = ( (A[i-1]+A[i-2])%M + A[i-3])%M;
        }
        return ( (A[n-1] % M + P[n-1]%M )%M + L[n-1]%M )%M;

    }
};