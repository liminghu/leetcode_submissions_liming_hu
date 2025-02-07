// https://leetcode.com/problems/reconstruct-itinerary


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        route_.clear();
		trips_.clear();
		
		for(const auto& pair:tickets)
			trips_[pair[0]].push_back(pair[1]);
		
		for(auto& pair: trips_) {
			auto& dests = pair.second; //value
			sort(dests.begin(), dests.end());
		}
		
		const string kStart = "JFK";
		visit(kStart);
		
		std::reverse(route_.begin(),route_.end());   
        return route_;
    }
private:
	vector<string> route_; //result, reversed.
	//src->{dst1, dst2, ...,dstn}
	unordered_map<string, deque<string>> trips_;  //graph.
	void visit(const string& src) {
		auto& dests = trips_[src];
		while(!dests.empty()) {
			//get the smallest.
			const string dest = dests.front();
			//remove the front.
			dests.pop_front();
			//visit
			visit(dest);
		}
		route_.push_back(src); //post order.
	}
};