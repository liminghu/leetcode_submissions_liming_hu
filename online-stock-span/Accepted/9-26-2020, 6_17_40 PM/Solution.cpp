// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
		int span = 1;
		while(!s_.empty() && price >=s_.top().first) {
		span += s_.top().second;
		s_.pop();
		}
		s_.push({price, span});
		return span;
	}
private:
	stack<pair<int, int>> s_;
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */