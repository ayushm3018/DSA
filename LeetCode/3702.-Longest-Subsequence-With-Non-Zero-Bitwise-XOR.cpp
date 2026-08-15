/*
 * LeetCode: 3702. Longest Subsequence With Non-Zero Bitwise XOR
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 * Language: C++
 * Runtime: 0 ms | Memory: 171.2 MB
 * 
 * You are given an integer array nums.
 * 
 * Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.
 * 
 * Example 2:
 * 
 * Input: nums = [2,3,4]
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= nums.length <= 10^5
 * 
 * 	  - 0 <= nums[i] <= 10^9
 */

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool nonZero = false;

        for (int x : nums) {
            xr ^= x;
            if (x != 0) {
                nonZero = true;
            }
        }

        if (xr != 0) return n;

        if (nonZero) return n - 1;

        return 0;
    }
};
