// https://leetcode.com/problems/range-module

/*A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented 
as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. 
Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval 
[left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently 
being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open 
interval [left, right).
*/
class RangeModule {
public:
    map<int, int> mp;
    RangeModule() {
        
    }
    
/*
      A            B         C         D
L____________   ______  __________R  _____
   left_____________________right
*/

/*
So if there are range of values that are "equal" with respect to the comparison being used, 
lower_bound gives you the first of this, 
upper_bound gives you one-past-the-end of these. 
This is the normal pattern of STL ranges [first, last).
value a a a b b b c c c
index 0 1 2 3 4 5 6 7 8
bound       l     u
*/
    void addRange(int left, int right) {
        int leftBound = left;
        auto iter1 = mp.lower_bound(left); //first greater than or equal to left.
        if( iter1!=mp.begin() && prev(iter1)->second >=leftBound ) {
            iter1 = prev(iter1);
            leftBound = iter1->first;
        }

        auto iter2 = mp.upper_bound(right); //first greater than right. open.
        int rightBound = right;
        if( iter2!=mp.begin() && prev(iter2)->second >=rightBound ) {
            rightBound = prev(iter2)->second;
        }
        mp.erase(iter1, iter2);  //Removes from the map container either a single element or a range of elements ([first,last)).
        mp[leftBound] = rightBound;        
    }
 /*
      A            B         C         D
L____________   ______  __________R  _____
   left_____________________right
*/

    bool queryRange(int left, int right) {
        auto iter = mp.upper_bound(left); //last greater than  left.

        return iter!=mp.begin() && prev(iter)->second >= right;
        
    }
 /*
      A            B         C         D
L____________   ______  __________R  _____
   left_____________________right
*/   
    void removeRange(int left, int right) {
        auto iter1 = mp.lower_bound(left); //first greater than or equal to left.
        int h1 = 0, t1 = 0;
        if(iter1 !=mp.begin() && prev(iter1)->second > left) {
            iter1 = prev(iter1);
            h1 = iter1->first;
            t1 = left;
        }
        auto iter2 = mp.upper_bound(right);
        int h2 = 0, t2 = 0;
        if(iter2 !=mp.begin() && prev(iter2)->second > right) {
            h2 = right;
            t2 = prev(iter2)->second;
        }

        mp.erase(iter1, iter2);
        if(h1!=0) mp[h1] = t1;
        if(h2!=0) mp[h2] = t2;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */