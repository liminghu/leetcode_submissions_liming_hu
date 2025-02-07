// https://leetcode.com/problems/minimum-total-distance-traveled

using LL = long long;
class Solution {
    //dp[i][j]表示前i个工厂覆盖了前j个机器人时，所需要的最小路径和
    LL dp[101][101]; //1 <= robot.length, factory.length <= 100
    LL dist[101][101][101]; //dist[i][j-k+1][k]表示最后k个机器人都送到第i个工厂时，所对应的总路程。
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.
        int m = robot.size();
        int n = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for(int i=0; i<n; i++) { //for n factories
            for(int j=0; j<m; j++) { //for m robots.
                LL sum = 0;
                for(int k=j; k<m; k++) {
                    sum += abs(factory[i][0]-robot[k]);
                    dist[i][j][k] = sum;  //dist[i][j-k+1][k]表示最后k个机器人都送到第i个工厂时，所对应的总路程。
                }
            }
        }
        //dp[0][j]
        dp[0][0] = 0;
        for(int j=1; j<=m; j++) {
            if(j<=factory[0][1])
                dp[0][j] = dist[0][0][j-1];
            else 
                dp[0][j] = LLONG_MAX/2;
        }
       for(int i=1; i<n; i++) { //for n factories
            for(int j=1; j<=m; j++) { //for m robots.       
                dp[i][j] = dp[i-1][j]; //k=0
                for(int k=0; k<=min(j, factory[i][1]); k++)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-k]+dist[i][j-k][j-1]);
            }
       } 
       return dp[n-1][m];
    }
};