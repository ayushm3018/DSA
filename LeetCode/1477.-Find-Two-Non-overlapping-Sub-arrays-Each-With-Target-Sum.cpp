/*
 * LeetCode: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * Language: C++
 * Runtime: 3 ms | Memory: 88.9 MB
 * 
 * You are given an array of integers arr and an integer target.
 * 
 * You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
 * 
 * Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: arr = [3,2,2,4,3], target = 3
 * Output: 2
 * Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
 * 
 * Example 2:
 * 
 * Input: arr = [7,3,4,7], target = 7
 * Output: 2
 * Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
 * 
 * Example 3:
 * 
 * Input: arr = [4,3,2,6,2,3,4], target = 6
 * Output: -1
 * Explanation: We have only one sub-array of sum = 6.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= arr.length <= 10^5
 * 
 * 	  - 1 <= arr[i] <= 1000
 * 
 * 	  - 1 <= target <= 10^8
 */

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0, currSum = 0;

        vector<int> minBestLen(n, INT_MAX);
        int bestMinLen = INT_MAX;
        int res = INT_MAX;

        while (j < n) {
            currSum += arr[j];

            while (i < j && currSum > target)
                currSum -= arr[i++];

            if (currSum == target) {
                int len = j - i + 1;

                if (i > 0 && minBestLen[i - 1] != INT_MAX)
                    res = min(res, len + minBestLen[i - 1]);

                bestMinLen = min(bestMinLen, len);
            }

            minBestLen[j] = bestMinLen;
            j++;
        }

        return res == INT_MAX ? -1 : res;
    }
};
