/*
 * LeetCode: 1621. Number of Sets of K Non-Overlapping Line Segments
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
 * Language: C++
 * Runtime: 51 ms | Memory: 34.8 MB
 * 
 * Given n points on a 1-D plane, where the i^th point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.
 * 
 * Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 10^9 + 7.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 4, k = 2
 * Output: 5
 * Explanation: The two line segments are shown in red and blue.
 * The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
 * 
 * Example 2:
 * 
 * Input: n = 3, k = 1
 * Output: 3
 * Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
 * 
 * Example 3:
 * 
 * Input: n = 30, k = 7
 * Output: 796297179
 * Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 10^9 + 7 gives us 796297179.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 2 <= n <= 1000
 * 
 * 	  - 1 <= k <= n-1
 */

class Solution {
public:
    int M = 1e9+7;
    int dp[1001][1001];
    int numberOfSets(int n, int K) {
        for(int i=0; i<=n-1;i++) dp[0][i]=1;
        for(int k=1; k<=K; k++){
            vector<int>prevRowSum(n+1,0);
            for(int x=n-1; x>=0; x--)
            prevRowSum[x]=(prevRowSum[x+1]+dp[k-1][x])%M;
            for(int i=n-1; i>=0; i--){
                int take =prevRowSum[i+1];
                
                int skip = dp[k][i+1]%M;
                dp[k][i]= (take+skip)%M;

            }
        }
        return dp[K][0];

    }
};
