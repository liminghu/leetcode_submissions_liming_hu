// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      
		vector<int> char_map(26,0); //frequency.
		for(char c: tasks) {
			char_map[c-'A']++;
		};
		sort(char_map.begin(), char_map.end()); //ascending.
		int max_val = char_map[25]-1; //max. the last one does not count, it does not need idle time.
		int idle_slots = max_val * n;
		
		for(int i = 24; i >= 0; i--) { //25 letters left.
			idle_slots -= min(char_map[i], max_val); 
		}
		
		return idle_slots > 0? idle_slots + tasks.size(): tasks.size();
		
			
    }
};