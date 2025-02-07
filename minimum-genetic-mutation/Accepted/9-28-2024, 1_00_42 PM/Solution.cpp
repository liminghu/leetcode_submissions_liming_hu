// https://leetcode.com/problems/minimum-genetic-mutation

/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation 
is defined as one single character changed in the gene string.
For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid 
gene string.
Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed 
to mutate from startGene to endGene. If there is no such a mutation, return -1.
Note that the starting point is assumed to be valid, so it might not be included in the bank.
0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
        //mutation: "AACCGGTT" --> "AACCGGTA"
        unordered_set<string> visited;
        queue<string> q;
        unordered_set<string> bank_set;
        for(int i=0; i<bank.size(); i++)
            bank_set.insert(bank[i]);
        
        if(!bank_set.contains(endGene))
            return -1;
        
        if(startGene == endGene)
            return 0;
        
        int res = 0;
        q.push(startGene);
        visited.insert(startGene);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                string cur = q.front();
                q.pop();
                
                if(cur == endGene)
                    return res;
                
                for(string str: bank) {
                    if(canMutate(str, cur) && !visited.contains(str)) {
                        q.push(str);
                        visited.insert(str);
                    };
                }
            }
            res++;
        };
        return -1;
    }

    bool canMutate(string des, string cur) {
        int count = 0;
        for(int i=0; i<cur.size(); i++) {
            if(des[i] != cur[i])
                count++;
        }
        return count==1;
    }
};