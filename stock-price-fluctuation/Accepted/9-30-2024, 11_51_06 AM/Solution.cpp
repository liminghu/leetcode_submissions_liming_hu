// https://leetcode.com/problems/stock-price-fluctuation

/*You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
Finds the maximum price the stock has been based on the current records.
Finds the minimum price the stock has been based on the current records.
Implement the StockPrice class:

StockPrice() Initializes the object with no price records.
void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
int current() Returns the latest price of the stock.
int maximum() Returns the maximum price of the stock.
int minimum() Returns the minimum price of the stock.
1 <= timestamp, price <= 109
At most 105 calls will be made in total to update, current, maximum, and minimum.
current, maximum, and minimum will be called only after update has been called at least once.
*/
class StockPrice {
private:
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater<pair<int,int>> > pq_min_; //min top.  //pair: price, timestamp.
    priority_queue< pair<int,int>, vector< pair<int,int> >, less< pair<int,int> > > pq_max_; //max top.   
    unordered_map<int, int> timestampPriceMap; //timestamp is the key. 
    int latestTime_;

public:
    StockPrice() { // Initializes the object with no price records.
        latestTime_ = 0;  
    }
    
    void update(int timestamp, int price) { //Updates the price of the stock at the given timestamp.
        latestTime_ = max(latestTime_, timestamp);
        timestampPriceMap[timestamp] = price;

        pq_min_.push({price, timestamp});
        pq_max_.push({price, timestamp});
    }
    
    int current() { //Returns the latest price of the stock.
        return timestampPriceMap[latestTime_];
    }
    
    int maximum() {
        pair<int, int> top = pq_max_.top();
        while(timestampPriceMap[top.second] != top.first) {//if the price in the max heap is not in the hash map.
          pq_max_.pop();
          top = pq_max_.top();
        }
        return top.first;
    }
    
    int minimum() {
        pair<int, int> top = pq_min_.top();
        while(timestampPriceMap[top.second] != top.first) {//if the price in the min heap is not in the hash map.
          pq_min_.pop();
          top = pq_min_.top();
        }
        return top.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */