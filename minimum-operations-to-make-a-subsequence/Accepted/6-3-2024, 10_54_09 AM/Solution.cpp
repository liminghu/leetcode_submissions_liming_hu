// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) { //an array target that consists of distinct integers and another integer array arr that can have duplicates.
        //In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. 
        //Note that you can insert the integer at the very beginning or end of the array.
        //Return the minimum number of operations needed to make target a subsequence of arr.
        //A subsequence of an array is a new array generated from the original array by deleting 
        //some elements (possibly none) without changing the remaining elements' relative order. 
        //For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

        //Since one of the arrays has distinct elements, we can consider that these elements describe an arrangement of numbers, 
        //and we can replace each element in the other array with the index it appeared at in the first array.
        
        /*
        (1) Since "target" array has distinct elements that means I can give every element an index which is unique to it.
        (2) Now let us delete all the elements in "arr" array which are not present in the target array.
        (3) What is left in "arr" array is all the elements which are present in target.
        (4) Replace each element in "arr" with its index from target array. What that means is if you have element "5" in arr and its index is 1 in target array then, you replace the element with that index.
        (5) Now you have indexes instead of elements.
        (6) Now you find the longest incresing subseqence. Why increasing? because remember the indexing the target array is 0,1,2,3,4,5,... so on.
        */
        unordered_map<int, int> target_d;
        int n = arr.size();
        
        for(int i=0; i<target.size(); i++) {
            target_d[target[i]]=i;
        };

        vector<int> stack;
        for(int a: arr) {
            if(target_d.find(a)==target_d.end())
                continue; //not found. ignore it.
            if(stack.empty() || target_d[a] > stack.back()) {
                stack.push_back(target_d[a]);
                continue;
            }

            int left=0, right = stack.size()-1, mid;
            while(left < right) {
                mid =(left+right)/2;
                if(stack[mid]<target_d[a])
                    left = mid+1;
                else
                    right = mid;
            }
            stack[left] = target_d[a];
        }

        return target.size() - stack.size();
    }
};