// https://leetcode.com/problems/trapping-rain-water

//Given n non-negative integers representing an elevation map where the width of each bar is 1, 
//compute how much water it can trap after raining.
class Solution {
public:
    void print(stack<int> &s)
    {
        if(s.empty())
        {
            cout << endl;
            return;
        }
        int x= s.top();
        s.pop();
        print(s);
        s.push(x);
        cout << x << " ";
    }
    int trap(vector<int>& height) {
        /*
            n == height.length
            1 <= n <= 2 * 104
            0 <= height[i] <= 105
        */

        if(height.size() <= 2 )
            return 0;
        int sz = height.size();

        vector<int> left_max(sz, 0);
        vector<int> right_max(sz, 0);
        left_max[0] = height[0];

        for(int i=1; i<sz; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        right_max[sz-1] = height[sz-1];
        for(int i=sz-2; i>=0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        int ans = 0;
        for(int i=1; i<sz-1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
 
 /*       int ans = 0;
        int sz = height.size();
        if( sz <= 2 )
            return 0;
        
        stack<int> st; 
        int i = 0;
        while (i < sz ) {
            while( !st.empty() && height[i] > height[st.top()]) { //have a trap.
               print(st);
               int top = st.top();
               st.pop();
               if(st.empty())
                    break; //no trap.
                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
                cout << endl << " i= " << i << endl; 
                cout << " bounded_height = " << bounded_height << " distance = " << distance << " ans = " << ans << endl;
            };
            st.push(i); //We add the index of the bar to the stack if bar is smaller than or equal to the bar at top of stack
            i++;
        }
        return ans; */
        
    }
};