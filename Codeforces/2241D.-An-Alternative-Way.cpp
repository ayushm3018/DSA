/*
 * Codeforces: 2241D. An Alternative Way
 * URL: https://codeforces.com/problemset/problem/2241/D
 * Language: C++20 (GCC 13-64)
 * 
 * D. An Alternative Waytime limit per test2 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given two arrays $$$a$$$ and $$$b$$$, each of length $$$n$$$. You are allowed to perform the following operation on array $$$a$$$ any number of times (including zero):  Choose two indices $$$l$$$ and $$$r$$$ such that $$$1 \le l \le r \le n$$$;  For each index $$$i$$$ from $$$l$$$ to $$$r$$$ (both inclusive),   Set $$$a_i := a_i - 1$$$ if $$$i - l$$$ is odd.  Set $$$a_i := a_i + 1$$$ if $$$i - l$$$ is even.  Determine whether you can make the array $$$a$$$ equal to the array $$$b$$$ by performing the operation any number of times.InputThe first line contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases. Description of each test case follows.The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 2\cdot10^5$$$) — the length of the arrays $$$a$$$ and $$$b$$$.The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le 10^9$$$) — the elements of the array $$$a$$$.The third line of each test case contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$1 \le b_i \le 10^9$$$) — the elements of the array $$$b$$$.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot10^5$$$.OutputFor each test case, print "YES" if you can make array $$$a$$$ equal to array $$$b$$$ and "NO" otherwise.You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).NoteFor the first test case, arrays $$$a$$$ and $$$b$$$ are already equal.For the second test case, let us choose $$$l = 2$$$ and $$$r = 4$$$. Now, we update the array $$$a$$$ in the following manner:  For $$$i = 2$$$, we have $$$i - l = 2 - 2 = 0$$$, which is even. Hence, set $$$a_2 := a_2 + 1 = 4 + 1 = 5$$$.  For $$$i = 3$$$, we have $$$i - l = 3 - 2 = 1$$$, which is odd. Hence, set $$$a_3 := a_3 - 1 = 5 - 1 = 4$$$.  For $$$i = 4$$$, we have $$$i - l = 4 - 2 = 2$$$, which is even. Hence, set $$$a_4 := a_4 + 1 = 2 + 1 = 3$$$. Finally, we have array $$$a = [1, 5, 4, 3]$$$ and array $$$b = [1, 5, 4, 3]$$$.For the third test case, it can be shown that it is impossible to make array $$$a$$$ equal to array $$$b$$$.
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    while(t--){
        
        cin>>n;
        vector<long long>a(n);
        for(int i=0 ; i<n; i++){
            cin>>a[i];
        }
        long long pre=0;
        bool pos = true;
        
        for(int i=0; i<n; i++){
            long long bval; cin>>bval;
            long long diff = bval-a[i];
            pre+=diff;
            if(pre<0) pos=false;
        }
        if(pos) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
