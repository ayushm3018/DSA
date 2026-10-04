/*
 * LeetCode: 678. Valid Parenthesis String
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/valid-parenthesis-string/
 * Language: C++
 * Runtime: 0 ms | Memory: 8.8 MB
 * 
 * Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
 * 
 * The following rules define a valid string:
 * 
 * 	  - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * 
 * 	  - Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * 
 * 	  - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * 
 * 	  - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 * 
 * Input: s = "(*)"
 * Output: true
 * 
 * Example 3:
 * 
 * Input: s = "(*))"
 * Output: true
 * 
 * Example 4:
 * 
 * Input: s = "("
 * Output: false
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= s.length <= 100
 * 
 * 	  - s[i] is '(', ')' or '*'.
 */

class Solution {
public:
    int t[101][101];

    bool solve(int idx, int open, string&s, int n){
        if(idx==n) return open==0;

        if(t[idx][open]!=-1) return t[idx][open];

        bool isValid = false;

        if(s[idx]=='*') {
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);

            if(open>0){
                isValid |= solve(idx+1, open-1, s, n);
            }
        }
        else if(s[idx]=='('){
            isValid |= solve(idx+1, open+1, s, n);
        }
        else if(open>0){
            isValid |= solve(idx+1, open-1, s, n);
        }

        return t[idx][open] = isValid;
    }

    bool checkValidString(string s) {
        memset(t, -1, sizeof(t));

        int n = s.length();
        return solve(0,0,s,n);
    }
};
