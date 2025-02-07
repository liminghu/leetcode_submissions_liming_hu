// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
private:
    //float min_price;
    //float max_price;
    unordered_map<int, int> price_hist; //key: timestamp, value: price.
    int cur_timestamp;
    map<int, int> priceFrequency; //sorted by key increasingly.

public:
    StockPrice() { // Initializes the object with no price records.
        cur_timestamp = -1;            
    }
    
    void update(int timestamp, int price) { //Updates the price of the stock at the given timestamp.
    
        if(timestamp>cur_timestamp)
            cur_timestamp = timestamp;

        if(price_hist.find(cur_timestamp)!=price_hist.end()) {
            int oldPrice = price_hist[timestamp];
            priceFrequency[oldPrice]--;
            if(priceFrequency[oldPrice]==0)
                priceFrequency.erase(oldPrice);
        }

        price_hist[timestamp] = price;
        priceFrequency[price]++;


    }
    
    int current() { //Returns the latest price of the stock.
        if(price_hist.find(cur_timestamp)!=price_hist.end())
            return price_hist[cur_timestamp];
        else
            return -1; //??
    }
    
    int maximum() {
        return priceFrequency.rbegin()->first;
    }
    
    int minimum() {
        return priceFrequency.begin()->first;
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