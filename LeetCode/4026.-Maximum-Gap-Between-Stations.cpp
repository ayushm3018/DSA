/*
 * LeetCode: 4026. Maximum Gap Between Stations
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-gap-between-stations/
 * Language: C++
 * Runtime: 75 ms | Memory: 72.1 MB
 * 
 * You are given two strings skill and station of lengths n and m, respectively.
 * 
 * skill[i] represents the skill of worker i, and station[j] represents the skill supported by station j.
 * 
 * You must assign every worker to a distinct station. Let ji be the index of the station assigned to worker i. A valid assignment must satisfy:
 * 
 * 	  - station[ji] == skill[i] for every 0 <= i < n.
 * 
 * 	  - The assigned station indices must be strictly increasing in worker order, meaning j0 < j1 < ... < jn - 1.
 * 
 * The gap of an assignment is the maximum difference between the station indices assigned to two consecutive workers. In other words, it is max(ji - ji - 1) over all 1 <= i < n.
 * 
 * If there is only one worker, the gap is 0.
 * 
 * Return the maximum possible gap among all valid assignments. It is guaranteed that at least one valid assignment exists.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: skill = "aa", station = "aaaa"
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * 	  - The two workers must be assigned to two different 'a' stations.
 * 
 * 	  - Assigning them to stations [0, 3] gives a gap of 3.
 * 
 * Example 2:
 * 
 * Input: skill = "xyz", station = "xyzz"
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * 	  - Assign worker 0 to station j = 0, and worker 1 to station j = 1.
 * 
 * 	  - To maximize the gap, assign worker 2 to station j = 3.
 * 
 * 	  - This gives the assignment [0, 1, 3] with gaps [1, 2], so the gap is 2.
 * 
 * Example 3:
 * 
 * Input: skill = "cbc", station = "cbcdbc"
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * 	  - Assign worker 0 to station j = 0, and worker 1 to station j = 1.
 * 
 * 	  - To maximize the gap, assign worker 2 to station j = 5.
 * 
 * 	  - This gives the assignment [0, 1, 5] with gaps [1, 4], so the gap is 4.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - skill.length == n
 * 
 * 	  - station.length == m
 * 
 * 	  - 1 <= n <= m <= 10^5
 * 
 * 	  - skill and station consist of lowercase English letters.
 * 
 * 	  - It is guaranteed that a valid assignment exists for every worker.
 */

class Solution {
public:
    int maximumGap(string skill, string station) {
      int n = skill.size(), m=station.size();
        vector<int>left(n); vector<int>right(n);

        int j=0;
        for(int i=0; i<n; i++){
            while(station[j]!=skill[i]){
                j++;
            }
            left[i]=j;
            j++;
        }
        j=m-1;
        for(int i=n-1; i>=0; i--){
            while(station[j]!=skill[i]){
                j--;
            }
            right[i]=j;
            j--;
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, right[i]-left[i-1]);
            
        }
        return ans; 
    }
};
