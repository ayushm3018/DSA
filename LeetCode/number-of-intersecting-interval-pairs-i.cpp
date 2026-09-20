/*
 * LeetCode: number of intersecting interval pairs i
 * URL: https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/
 * Language: C++
 * Runtime: 4 ms | Memory: 36.3 MB
 */

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(intervals[i][1]>=intervals[j][0] and intervals[j][1]>=intervals[i][0]) ans++;
            }
        }
        return ans;
    }
};
