/*
 * LeetCode: minimum operations to make a rotated palindrome i
 * URL: https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
 * Language: C++
 * Runtime: 188 ms | Memory: 11.2 MB
 */

class Solution {
public:
    int minOperations(string s) {
        int n= s.length(), minOps = INT_MAX;
        string ss = s+s;
        for(int k =0; k<n; k++){
            int rc = k;
            int ic = 0;
            for(int i=0; i<n/2; i++){
                int c1=ss[k+i]-'a', c2=ss[k+n-1-i]-'a', diff1=(c2-c1+26)%26, diff2=(c1-c2+26)%26;
                ic+=min(diff1,diff2);
                
            }
            minOps = min(minOps, rc+ic);
        }
        return minOps;
        
    }
};
