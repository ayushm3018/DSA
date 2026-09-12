/*
 * LeetCode: count values with equally spaced occurrences ii
 * URL: https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/
 * Language: C++
 * Runtime: 215 ms | Memory: 294 MB
 */

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>>pos;
        for(int i=0; i<nums.size(); i++) pos[nums[i]].push_back(i);

        int ans=0;
        for(auto&p: pos){
            vector<int>&v = p.second;
            if(v.size()<3){
               continue;
                
            }
            int diff = v[1]-v[0];
            bool s = true;
            for(int i=2; i<v.size(); i++){
                if(v[i]-v[i-1]!=diff){
                    s=false;
                    break;
                }
            }
            if(s) ans++;
        }
        return ans;
    }
};
