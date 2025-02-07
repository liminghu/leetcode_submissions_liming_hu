// https://leetcode.com/problems/online-election

class TopVotedCandidate {
private:
    unordered_map<int, int> p_lead; //time, person_lead.
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(); 
        int lead = -1;
        this->times = times;
        unordered_map<int,int> count; //person, count.
        for(int i=0; i<n; i++) {
            count[persons[i]]++;
            if(count[persons[i]] >= count[lead])
                lead = persons[i];
            p_lead[times[i]] = lead;
        }
    }
    
    int q(int t) {
        auto it = --upper_bound(times.begin(), times.end(), t);
        return p_lead[*it];

        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */