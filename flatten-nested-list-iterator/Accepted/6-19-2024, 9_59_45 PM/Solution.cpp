// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> IntList;
    vector<NestedInteger> nestedList;
    int cur = 0;
   
    
public:      
    NestedIterator(vector<NestedInteger> &nestedList) { //Initializes the iterator with the nested list nestedList.
    this->nestedList = nestedList;
    //this->IntList = {};
    flatten(nestedList);

    }
    
    void flatten(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        for(int i=0; i<sz; i++) {
            if(nestedList[i].isInteger()) {
                IntList.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList());                 
            }
        }

    }
    
    int next() { //Returns the next integer in the nested list.
            int res = IntList[cur];    
            cur++;
            //IntList.pop_back();
            return res;
    }
        
    
    bool hasNext() { //Returns true if there are still some integers in the nested list and false otherwise.
        if(cur <IntList.size())
            return true;
        else
            return false;
        
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */