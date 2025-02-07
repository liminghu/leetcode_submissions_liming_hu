// https://leetcode.com/problems/all-oone-data-structure

/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
Implement the AllOne class:
AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data 
structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.
*/
/*1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
*/
class AllOne {
    list<int> List; //ordered sequence of values;
    unordered_map<int,list<int>::iterator> val2iter; //val->iterator in list
    unordered_map<string,int> key2val;  //key->val 
    unordered_map<int,unordered_set<string>> val2set;  //val -> set of keys.

public:
    AllOne() {
        List.push_back(0); //dummy
        val2iter[0] = List.begin();
    }
    
    void inc(string key) {
        int val = key2val[key]; //if not found, val will be 0.
        key2val[key] += 1;
        val2set[val+1].insert(key);
        if( val > 0 ) 
            val2set[val].erase(key);
        
        if(val2set[val+1].size() == 1) { //val+1 does not exist before.
            List.insert( next( val2iter[val] ), val+1 ); //insert val+1 to the list.
            val2iter[val+1] = next(val2iter[val]); //record val+1 pos in the list.
        }

        if( val > 0 && val2set[val].size() == 0) { //val existed, and does not exist any more.
            List.erase(val2iter[val]);
        }
        
    }
    
    void dec(string key) {
        int val = key2val[key];
        if( val == 0 ) 
            return;
        key2val[key] = val-1;
        if( val-1 > 0 )
            val2set[val-1].insert(key);
        val2set[val].erase(key);
        if(val-1>0 && val2set[val-1].size() == 1) { //val-1 does not exist.
            List.insert( val2iter[val], val-1 );
            val2iter[val-1] = prev( val2iter[val] );
        }
        if(val2set[val].size()==0) {
            List.erase(val2iter[val]);
        }
        
    }
    
    string getMaxKey() {
        if(List.size() == 1 )
            return "";
        else {
            return *val2set[ List.back() ].begin();
        }
    }
    
    string getMinKey() {
        if(List.size() == 1)
            return "";
        else {
            list<int>::iterator it = List.begin(); //dummy head.
            it++;
            return *val2set[ *it ].begin();
        }
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */