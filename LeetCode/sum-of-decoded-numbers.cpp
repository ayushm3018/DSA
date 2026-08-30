/*
 * LeetCode: sum of decoded numbers
 * URL: https://leetcode.com/problems/sum-of-decoded-numbers/
 * Language: C++
 * Runtime: 43 ms | Memory: 88.7 MB
 */

class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    ll power(ll x, ll y){
        ll ans =1;
        while(y){
            if(y&1) ans= ans*x%MOD;
            x = x*x%MOD;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        ll ans =0;
        for(ll num: nums){
            int width = num%10;
            ll d = num/10; ll temp = d; int digits = 0;
            while(temp)
                {
                    digits++; temp/=10;
                }
            int yD = digits-width;
            ll p =1;
            for(int i=0; i<yD; i++){
                p*=10; }
                ll x = d/p;
                ll y = d%p;
                ans = (ans+power(x,y))%MOD;
            
        }
        return ans;
        

        

        
    }
};
