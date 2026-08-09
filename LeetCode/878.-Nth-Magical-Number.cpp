/*
 * LeetCode: 878. Nth Magical Number
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/nth-magical-number/
 * Language: C++
 * Runtime: 0 ms | Memory: 7.8 MB
 * 
 * A positive integer is magical if it is divisible by either a or b.
 * 
 * Given the three integers n, a, and b, return the n^th magical number. Since the answer may be very large, return it modulo 10^9 + 7.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 1, a = 2, b = 3
 * Output: 2
 * 
 * Example 2:
 * 
 * Input: n = 4, a = 2, b = 3
 * Output: 6
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - 1 <= n <= 10^9
 * 
 * 	  - 2 <= a, b <= 4 * 10^4
 */

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        /*  intial thought brute force that came to mind
        int cnt =0; long long temp=0;
        const long long MOD = 1e9+7;
        int smaller = min(a,b);
        for(int i=smaller; cnt<n; i++){
            if((i%a==0)or (i%b==0)) {cnt++; temp=i;}
        }
        return temp%MOD; */
        using ll = long long;
        const ll MOD = 1e9+7;
        ll lcm = 1LL * a/gcd(a,b)*b;
        ll low = 1;
        ll high = 1LL*n*min(a,b);

        while(low<high){
            ll mid = low+(high-low)/2;
            ll divByA = mid/a;
            ll divByB = mid/b;
            ll divByBoth = mid/lcm;
            ll cnt = divByA+divByB-divByBoth;

            if(cnt>=n) high=mid;
            else low = mid+1;
            
        }
        return low%MOD;
        
    }
};
