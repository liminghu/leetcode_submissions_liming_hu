// https://leetcode.com/problems/find-median-from-data-stream

/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 */
class MedianFinder {
    priority_queue<int> lo;     //max heap.
    priority_queue<int, vector<int>, greater<int>> hi;  //min healp.

public:
    MedianFinder() {    
    }
    
    void addNum(int num) {
        lo.push(num);    //add to max heap.
        hi.push(lo.top());   //balancing the two heaps.
        lo.pop();

        if(lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        
        return lo.size() > hi.size()? lo.top(): (double)(lo.top()+hi.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */