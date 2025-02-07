// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
	if(i_==0 || price < prices_.back()) {
		dp_.push_back(1);
	} else {
		int j = i_ -1;
		while(j>=0 && price >=prices_[j]) {
			j -= dp_[j];
		}
		dp_.push_back(i_ - j);
	}
	i_++;
	prices_.push_back(price);
	return dp_.back();
		
    }
private:
	vector<int> dp_;
	vector<int> prices_;
	int i_ = 0;
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */