/*
 * LeetCode: number of intersecting interval pairs ii
 * URL: https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/
 * Language: C++
 * Runtime: 132 ms | Memory: 258.7 MB
 */

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long ans=0;
        for(auto& it : intervals){
            int start =it[0], end = it[1];
            while(!pq.empty() and pq.top()<start) pq.pop();

            ans+=pq.size();
            pq.push(end);
        }
        return ans;
    }
};
