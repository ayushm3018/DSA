/*
 * LeetCode: k th digit in infinite string
 * URL: https://leetcode.com/problems/k-th-digit-in-infinite-string/
 * Language: C++
 * Runtime: 0 ms | Memory: 9.4 MB
 */

class Solution {
public:
    using ll = long long;
    int kthDigit(long long k) {
        if(k<=9) return k;
        k-=9;
        ll b=1, digits=2;
        while(true){
            ll cnt = 9;
            for(int i=1; i<digits-1;i++)
                cnt*=10;
                ll blocks = cnt;
                ll groupLen = blocks*10*digits;
                if(k>groupLen){
                    k-=groupLen; b+=blocks; digits++;
                }
                else {
                    break;
                }
        }
            ll blockOffSet = (k-1)/(10*digits);
        b+= blockOffSet;
            ll pos = (k-1)%(10*digits);
            ll nI = pos/digits, dI = pos%digits;
        
            ll start=10*b, num;
            if(b%2==0) num=start+nI;
            else num=start+9-nI;
        string str = to_string(num);
        
         return str[dI]-'0';
        
    }
};
