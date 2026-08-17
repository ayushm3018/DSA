/*
 * LeetCode: 857. Minimum Cost to Hire K Workers
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
 * Language: C++
 * Runtime: 15 ms | Memory: 31.9 MB
 * 
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the i^th worker and wage[i] is the minimum wage expectation for the i^th worker.
 * 
 * We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
 * 
 * 	  - Every worker in the paid group must be paid at least their minimum wage expectation.
 * 
 * 	  - In the group, each worker's pay must be directly proportional to their quality. This means if a worker&rsquo;s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
 * 
 * Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10^-5 of the actual answer will be accepted.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: quality = [10,20,5], wage = [70,50,30], k = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0^th worker and 35 to 2^nd worker.
 * 
 * Example 2:
 * 
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0^th worker, 13.33333 to 2^nd and 3^rd workers separately.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - n == quality.length == wage.length
 * 
 * 	  - 1 <= k <= n <= 10^4
 * 
 * 	  - 1 <= quality[i], wage[i] <= 10^4
 */

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>>workers;
        for(int i=0; i<n; i++){
            double ratio = (double)wage[i]/quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int>pq;
        long long totalQuality = 0;
        double ans = 1e18;
        for(auto it : workers){
            double ratio = it.first;
            int q = it.second;
            pq.push(q);
            totalQuality+=q;
            if(pq.size()>k){
                totalQuality-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = min(ans, totalQuality*ratio);
            }
        }
        return ans;
    }
};
