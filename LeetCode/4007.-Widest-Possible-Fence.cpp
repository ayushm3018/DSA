/*
 * LeetCode: 4007. Widest Possible Fence
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/widest-possible-fence/
 * Language: C++
 * Runtime: 1271 ms | Memory: 405.2 MB
 * 
 * You are given an integer array planks, where planks[i] represents the height of the i^th wooden plank. Each plank has a width of 1 unit.
 * 
 * You want to build a fence consisting of planks that all have the same height.
 * 
 * You may either use a plank as is, or combine exactly two distinct original planks into a single plank whose height equals the sum of their heights. Each original plank can be used at most once, and not all original planks need to be used.
 * 
 * Return the maximum possible width of the fence that can be built.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: planks = [1,3,2,5,7,5,4,2,1]
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * We can have four planks of height 5.
 * 
 * 	  - planks[3] = 5
 * 
 * 	  - planks[5] = 5
 * 
 * 	  - planks[0] + planks[6] = 1 + 4 = 5
 * 
 * 	  - planks[1] + planks[2] = 3 + 2 = 5
 * 
 * Hence, the maximum width is 4.
 * 
 * Example 2:
 * 
 * Input: planks = [2,3,7]
 * 
 * Output: 1
 * 
 * Explanation:
 * 
 * 	  - It is impossible to form two planks of the same height, even after combining two distinct original planks.
 * 
 * 	  - Since not all original planks need to be used, we can choose any one plank as the fence.
 * 
 * 	  - Therefore, the maximum possible width is 1.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= planks.length <= 1000
 * 
 * 	  - 1 <= planks[i] <= 10^9
 */

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long, int>freq;
        unordered_map<long long, int>fence;

        for(int x: planks) freq[x]++;

        int ans = 1;
        vector<pair<long long, int>>vec(freq.begin(), freq.end());
        int m = vec.size();
        for(int i=0; i<m; i++){
            long long x = vec[i].first;
            int countX = vec[i].second;

            fence[x]+=countX;
            ans = max(ans, fence[x]);

            if(countX>=2){
                fence[2*x]+=countX/2;
                ans = max(ans, fence[2*x]);
            }
            for(int j=i+1; j<m; j++){
                long long y = vec[j].first;
                int countY = vec[j].second;

                fence[x+y]+=min(countX, countY);
                ans = max(ans, fence[x+y]);
            }
        }
        return ans;
    }
};
