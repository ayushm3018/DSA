/*
 * LeetCode: 3090. Maximum Length Substring With Two Occurrences
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 * Language: C++
 * Runtime: 3 ms | Memory: 9 MB
 * 
 * Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 *  
 * 
 * Example 1:
 * 
 * Input: s = "bcbbbcba"
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 * 
 * Example 2:
 * 
 * Input: s = "aaaa"
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 2 <= s.length <= 100
 * 
 * 	  - s consists only of lowercase English letters.
 */

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>f(26,0);
        int l=0, ans=0, r=0;
        while(r<s.size()){
            f[s[r]-'a']++;
            while(f[s[r]-'a']>2){
                f[s[l]-'a']--;
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
