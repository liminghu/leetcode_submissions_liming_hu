// https://leetcode.com/problems/invalid-transactions

class Transaction {
    public:
        string name;
        int tTime;
        int amount;
        string city;
    Transaction(string name, int tTime, int amount, string city) {
        this->name = name;
        this->tTime = tTime;
        this->amount = amount;
        this->city = city;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        //the amount exceeds $1000, or;
        //if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.  
        int n = transactions.size();
        vector<bool> isValid(n, true);
        vector<Transaction> inputs;
        for(int i=0; i<n; i++) {
            string curTrans = transactions[i];
            string name;
            string time;
            string amount;
            string city;
            int j=0;
            while(curTrans[j]!=',')
                name += curTrans[j++];
            j++;
           while(curTrans[j]!=',')
                time += curTrans[j++];
            j++; 
           while(curTrans[j]!=',')
                amount += curTrans[j++];
            j++;      
            while(j<curTrans.size() )       //"alice,20,800,mtv"
                city += curTrans[j++];
            Transaction newTrans(name, stoi(time), stoi(amount), city);
            inputs.push_back(newTrans);
        }
        for(int i=0; i<n; i++) {
            if(inputs[i].amount > 1000)
                isValid[i] = false;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(inputs[i].name == inputs[j].name && inputs[i].city != inputs[j].city) {
                    int timediff = abs(inputs[i].tTime - inputs[j].tTime);
                    if(timediff <= 60) {
                        isValid[i] = false;
                        isValid[j] = false;
                    }
                }
            }
        }
        vector<string> invalidTrans;
        for(int i=0; i<n; i++) {
            if(!isValid[i])
                invalidTrans.push_back(transactions[i]);
        }
        return invalidTrans;
    }
 
};