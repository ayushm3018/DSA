/*
 * LeetCode: 3083. Existence of a Substring in a String and Its Reverse
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/
 * Language: C++
 * Runtime: 0 ms | Memory: 8.4 MB
 * 
 * Given a string s, find any substring of length 2 which is also present in the reverse of s.
 * 
 * Return true if such a substring exists, and false otherwise.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "leetcode"
 * 
 * Output: true
 * 
 * Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
 * 
 * Example 2:
 * 
 * Input: s = "abcba"
 * 
 * Output: true
 * 
 * Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
 * 
 * Example 3:
 * 
 * Input: s = "abcd"
 * 
 * Output: false
 * 
 * Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= s.length <= 100
 * 
 * 	  - s consists only of lowercase English letters.
 */

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1; j++){
                if(s[i]==s[j+1] and s[i+1]==s[j])
                return true;
            }
        }
return false;
    }
};
