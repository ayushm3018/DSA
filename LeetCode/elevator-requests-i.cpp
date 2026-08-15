/*
 * LeetCode: elevator requests i
 * URL: https://leetcode.com/problems/elevator-requests-i/
 * Language: C++
 * Runtime: 0 ms | Memory: 31.1 MB
 */

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int s = 0, f = requests.size(), prev=0, ans=0;
        for(int i=0; i<f; i++){
            ans+=abs(prev-requests[i]);
            prev=requests[i];
        }
        return ans;
    }
};
