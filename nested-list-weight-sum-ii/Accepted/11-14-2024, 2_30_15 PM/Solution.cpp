// https://leetcode.com/problems/nested-list-weight-sum-ii

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for(int i=0; i<nestedList.size(); i++)
            q.push(nestedList[i]);
        int depth = 1;
        int sum = 0;
        int extra = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                NestedInteger t = q.front();
                q.pop();
                if(t.isInteger()) {
                    sum += t.getInteger();
                    extra += t.getInteger() * depth;
                } else {
                    vector<NestedInteger> v_t = t.getList();
                    for(int j=0; j<v_t.size(); j++)
                        q.push(v_t[j]);
                }
            }
            depth++;
        }
        return sum*depth - extra;
    }
};