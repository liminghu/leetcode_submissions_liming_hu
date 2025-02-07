// https://leetcode.com/problems/smallest-number-in-infinite-set

/*
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
Implement the SmallestInfiniteSet class:
SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
1 <= num <= 1000
At most 1000 calls will be made in total to popSmallest and addBack.
*/
class SmallestInfiniteSet {
private:
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> added_pq;
    int smallest;

public:
    SmallestInfiniteSet() {
        isPresent.clear();
        smallest = 1;
    }
    
    int popSmallest() {
        int ret;
        if(!added_pq.empty()) {
            ret = added_pq.top();
            isPresent.erase(ret);
            added_pq.pop(); 
        } else {
            ret = smallest;
            smallest += 1;
        }
        return ret;
        
    }
    
    void addBack(int num) {
        if(smallest <= num || isPresent.find(num) !=isPresent.end())
            return;
        added_pq.push(num);
        isPresent.insert(num); 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */