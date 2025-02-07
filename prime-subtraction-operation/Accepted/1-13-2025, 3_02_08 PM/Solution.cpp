// https://leetcode.com/problems/prime-subtraction-operation

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        //Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
        int n = nums.size();
        vector<int> primes;
        for(int i=2; i<=1000; i++) {
            if(isPrime(i))
                primes.push_back(i);
        };
        int l = 0, h = 0;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]>=nums[i+1]) {
                l = (nums[i] - nums[i+1]) + 1;
                h = nums[i];
                int p = getPrime(primes, l, h);
                if(p==h)
                    return false;
                else
                    nums[i] -= p;
            }
        }
        return true;
    }
    bool isPrime(int num) {
        for(int i=2; i*i<=num; i++) {
            if(num%i==0)
                return false;
        }
        return true;
    }
    int getPrime(const vector<int>& primes, int l, int h) {
        for(int prime:primes) {
            if(l<=prime && prime<h)
                return prime;
        }
        return h;
    }
};