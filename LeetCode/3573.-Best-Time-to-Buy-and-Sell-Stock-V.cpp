/*
 * LeetCode: 3573. Best Time to Buy and Sell Stock V
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/
 * Language: C++
 * Runtime: 726 ms | Memory: 343.3 MB
 * 
 * You are given an integer array prices where prices[i] is the price of a stock in dollars on the i^th day, and an integer k.
 * 
 * You are allowed to make at most k transactions, where each transaction can be either of the following:
 * 
 * 	  - 
 * 	Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
 * 
 * 	
 * 
 * 	  - 
 * 	Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
 * 
 * 	
 * 
 * Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
 * 
 * Return the maximum total profit you can earn by making at most k transactions.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: prices = [1,7,9,8,2], k = 2
 * 
 * Output: 14
 * 
 * Explanation:
 * 
 * We can make $14 of profit through 2 transactions:
 * 
 * 	  - A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
 * 
 * 	  - A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.
 * 
 * Example 2:
 * 
 * Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
 * 
 * Output: 36
 * 
 * Explanation:
 * 
 * We can make $36 of profit through 3 transactions:
 * 
 * 	  - A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
 * 
 * 	  - A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
 * 
 * 	  - A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 2 <= prices.length <= 10^3
 * 
 * 	  - 1 <= prices[i] <= 10^9
 * 
 * 	  - 1 <= k <= prices.length / 2
 */

class Solution {
public:
    using ll = long long ;

    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<ll>>dp(k+1, vector<ll>(3, LLONG_MIN));
        dp[0][0]=0;
        for(int p:prices){
            vector<vector<ll>>ndp=dp;
            for(int t=0; t<=k; t++){
                if(dp[t][0]!=LLONG_MIN)
                    ndp[t][1]=max(ndp[t][1], dp[t][0]-p);

                if(dp[t][0]!=LLONG_MIN)
                    ndp[t][2] = max(ndp[t][2], dp[t][0]+p);

                if(t<k and dp[t][1]!=LLONG_MIN)
                ndp[t+1][0] = max(ndp[t+1][0], dp[t][1]+p);

                if(t<k and dp[t][2]!=LLONG_MIN)
                ndp[t+1][0]=max(ndp[t+1][0], dp[t][2]-p);
            }
            dp=ndp;
        }
        ll ans=0;
        for(int t=0; t<=k; t++){
            ans = max(ans, dp[t][0]);
        }
        return ans; 
        
    }
};
