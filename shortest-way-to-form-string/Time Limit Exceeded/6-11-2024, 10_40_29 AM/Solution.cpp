// https://leetcode.com/problems/shortest-way-to-form-string

class Solution {
public:
    int shortestWay(string source, string target) {
         //1 <= source.length, target.length <= 1000
        //source and target consist of lowercase English letters.
        
        //look for maximum subsequence
        int i=0;
        int begin =0; 
        int j =0;
        int count =0;
        
        while(j<target.length()) {
            j=begin;
            while(i<source.length()) {
                if(source[i] == target[j]) 
                    j++;
                i++;
            }
            if(j=begin)
                return -1;
            else
                count++;
            i=0;
            begin = j;
        }
        return count;       
    }
};