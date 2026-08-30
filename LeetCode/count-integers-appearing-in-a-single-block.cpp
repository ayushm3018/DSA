/*
 * LeetCode: count integers appearing in a single block
 * URL: https://leetcode.com/problems/count-integers-appearing-in-a-single-block/
 * Language: C++
 * Runtime: 0 ms | Memory: 21 MB
 */

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int>b(101, 0);
        for(int i=0; i<nums.size(); i++){
            if(i==0 or nums[i]!=nums[i-1]) b[nums[i]]++;
        }
int ans=0;
            for(int i=0; i<=100; i++){
                if(b[i]==1) ans++;
            }
                return ans;
    }
};
