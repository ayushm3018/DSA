/*
 * LeetCode: 2982. Find Longest Special Substring That Occurs Thrice II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/
 * Language: C++
 * Runtime: 87 ms | Memory: 53.8 MB
 * 
 * You are given a string s that consists of lowercase English letters.
 * 
 * A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
 * 
 * Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
 * 
 * A substring is a contiguous non-empty sequence of characters within a string.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "aaaa"
 * Output: 2
 * Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
 * It can be shown that the maximum length achievable is 2.
 * 
 * Example 2:
 * 
 * Input: s = "abcdef"
 * Output: -1
 * Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
 * 
 * Example 3:
 * 
 * Input: s = "abcaba"
 * Output: 1
 * Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
 * It can be shown that the maximum length achievable is 1.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 3 <= s.length <= 5 * 10^5
 * 
 * 	  - s consists of only lowercase English letters.
 */

class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>>runs(26);
        int i=0, n=s.size();
        while(i<n){
            int j=i;
            while(j<n and s[j]==s[i]) j++;

            int len = j-i;
            runs[s[i]-'a'].push_back(len); i=j;
        }
        int ans = -1;
        for(int c=0; c<26; c++){
            sort(runs[c].rbegin(), runs[c].rend());
            int a = runs[c].size()>0?runs[c][0]:0;
            int b = runs[c].size()>1?runs[c][1]:0;
            int d = runs[c].size()>2?runs[c][2]:0;

            int best = max({a-2, min(a-1, b), d});
            ans = max(ans, best);
        }
        if(ans<=0) return -1;
        return ans;
        
    }
};
