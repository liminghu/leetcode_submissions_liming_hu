// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed

class RandomizedCollection {
/*
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). 
It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the 
item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. 
Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being 
returned is linearly related to the number of the same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least 
one item in the RandomizedCollection.
*/
private:
    unordered_map<int, unordered_set<int>> dict; //key: val. unordered_set<int>: the index of val in the vector.
    vector<int> nums;   //store all the numbers even they have duplicates.

public:
    RandomizedCollection() { //RandomizedCollection() Initializes the empty RandomizedCollection object.
        dict = unordered_map<int, unordered_set<int>>();
        nums = vector<int>();
    }
    
    //bool insert(int val) Inserts an item val into the multiset, even if the item is already present. 
    //Returns true if the item is not present, false otherwise.
    bool insert(int val) {
        nums.push_back(val);
        dict[val].insert(nums.size()-1);
        return dict[val].size() == 1;
    }
    
    //bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present,
    // false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
    bool remove(int val) {
       auto it = dict.find(val);
       if( it != dict.end() ) {
        //Remove any index of the element being removed
        auto idx = *it->second.begin(); //idx in the nums vector.
        dict[val].erase(idx);

        //Swap the last element in the vector with the element being removed
        nums[idx] = nums.back(); //move the last num to the available slot.
        //Remove old and add new index for the swapped (last) element
        dict[nums.back()].insert(idx);
        //delete the last element.
        dict[nums.back()].erase(nums.size()-1);
        nums.pop_back();

        if(dict[val].size() == 0)
            dict.erase(val);
            return true;
        } else {
            return false;
        }        
    }
    
    int getRandom() { 
    //int getRandom() Returns a random element from the current multiset of elements. The probability of each element being 
    //returned is linearly related to the number of the same values the multiset contains.
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */