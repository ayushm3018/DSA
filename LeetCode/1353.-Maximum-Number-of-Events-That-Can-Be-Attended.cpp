/*
 * LeetCode: 1353. Maximum Number of Events That Can Be Attended
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * Language: C++
 * Runtime: 59 ms | Memory: 75 MB
 * 
 * You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
 * 
 * You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * 
 * Example 2:
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= events.length <= 10^5
 * 
 * 	  - events[i].length == 2
 * 
 * 	  - 1 <= startDayi <= endDayi <= 10^5
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = events.size();
        int i=0, day=0, ans=0;
        while(i<n|| !pq.empty()){
            if(pq.empty()) day=events[i][0];

            while(i<n and events[i][0]<=day) pq.push(events[i++][1]);

            while(!pq.empty() and pq.top()<day) pq.pop();

            if(!pq.empty()){pq.pop(); ans++; day++;}
        }
        return ans;
    }
};
