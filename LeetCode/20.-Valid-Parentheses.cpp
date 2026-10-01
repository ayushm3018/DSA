/*
 * LeetCode: 20. Valid Parentheses
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/valid-parentheses/
 * Language: C++
 * Runtime: 0 ms | Memory: 8.9 MB
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 	  - Open brackets must be closed by the same type of brackets.
 * 
 * 	  - Open brackets must be closed in the correct order.
 * 
 * 	  - Every close bracket has a corresponding open bracket of the same type.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "()"
 * 
 * Output: true
 * 
 * Example 2:
 * 
 * Input: s = "()[]{}"
 * 
 * Output: true
 * 
 * Example 3:
 * 
 * Input: s = "(]"
 * 
 * Output: false
 * 
 * Example 4:
 * 
 * Input: s = "([])"
 * 
 * Output: true
 * 
 * Example 5:
 * 
 * Input: s = "([)]"
 * 
 * Output: false
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= s.length <= 10^4
 * 
 * 	  - s consists of parentheses only '()[]{}'.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s){
         if(i == '(' || i == '{' || i == '[') st.push(i);
         else{ 
            
            if(st.empty()) return false;
            char ch = st.top();
            if(st.empty() || (ch == '(' && i!= ')') || (ch == '{' && i!= '}') || (ch == '[' && i!= ']')) return false;
            st.pop();
         }
 
        } return st.empty();
    }
};
