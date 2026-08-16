/*
 * LeetCode: 2108. Find First Palindromic String in the Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
 * Language: C++
 * Runtime: 15 ms | Memory: 26.6 MB
 * 
 * Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
 * 
 * A string is palindromic if it reads the same forward and backward.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: words = ["abc","car","ada","racecar","cool"]
 * Output: "ada"
 * Explanation: The first string that is palindromic is "ada".
 * Note that "racecar" is also palindromic, but it is not the first.
 * 
 * Example 2:
 * 
 * Input: words = ["notapalindrome","racecar"]
 * Output: "racecar"
 * Explanation: The first and only string that is palindromic is "racecar".
 * 
 * Example 3:
 * 
 * Input: words = ["def","ghi"]
 * Output: ""
 * Explanation: There are no palindromic strings, so the empty string is returned.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= words.length <= 100
 * 
 * 	  - 1 <= words[i].length <= 100
 * 
 * 	  - words[i] consists only of lowercase English letters.
 */

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it: words){
            int i=0, j=it.size()-1;
            bool flag = true;

            while(i<j){
                if(it[i]!=it[j]){
                    flag = false; break;
                }
                i++; j--;
            }
            if(flag) return it;
        }
        return "";
    }
};
