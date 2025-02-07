// https://leetcode.com/problems/split-message-based-on-limit

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        //how many digits
        for(int len =1; 3+len*2<limit; len++) { //3+len*2: <len/len>
            int num=pow(10, len)-1; //maximum for len of digits.
            int cost = (3+len)*num; //fixed cost.
            for(int i=1; i<=len; i++)
                cost += i * ( pow(10, i)-1 - (pow(10, i-1)-1) );
            if(limit*num-cost >=message.size())
                return get(message, limit, len); 
        };
        return {}; 
    }
    vector<string> get(string message, int limit, int len) {
        vector<string> rets;
        int count = 0;
        int idx = 0;
        while(count < message.size()) {
            idx++;
            int cost = 3+len+ to_string(idx).size();
            int add =min(limit-cost, (int)message.size()-count);
            rets.push_back(message.substr(count, add) + "<" + to_string(idx)+ "/");
            count += add;
        };
        for(auto& ret:rets)
            ret += to_string(idx)+">";
        return rets;
    }
};