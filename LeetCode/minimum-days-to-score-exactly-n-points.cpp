/*
 * LeetCode: minimum days to score exactly n points
 * URL: https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/
 * Language: C++
 * Runtime: 226 ms | Memory: 15.4 MB
 */

class Solution {
public:
    int minDays(int n) {
        const int INF = 1e9;
        vector<int>dp(n+1, INF);
        dp[0]=-1;
        for(int i=1; i<=n; i++){
            for(int k=1; k*(k+1)/2<=i; k++){
                int p = k*(k+1)/2;
                dp[i] = min(dp[i], dp[i-p]+k+1);
            }
        }
        return dp[n];
    }
};
