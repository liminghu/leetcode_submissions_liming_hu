// https://leetcode.com/problems/moving-average-from-data-stream

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
Implement the MovingAverage class:
MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
*/
class MovingAverage {
private:
  int max_size;
  int cur_size;
  queue<int> stream;
  double sum;

public:
    MovingAverage(int size) {
        max_size = size;
        cur_size = 0; 
        sum = 0;
    }
    
    double next(int val) {
        double result = 0;
        if (cur_size < max_size) {
            stream.push(val);
            cur_size++;
            sum = sum+ val;
            result = sum;
            return result/cur_size;
        } else { 
            sum = sum - stream.front();
            stream.pop();
            stream.push(val);
            sum = sum + val;
            result = sum;
            return result/max_size;
        }
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */