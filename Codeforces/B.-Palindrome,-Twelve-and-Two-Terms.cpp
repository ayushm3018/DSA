/*
 * Codeforces: B. Palindrome, Twelve and Two Terms
 * URL: https://codeforces.com/contest/2234/problem/B
 * Language: C++20 (GCC 13-64)
 * 
 * B. Palindrome, Twelve and Two Termstime limit per test1.5 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputYou are given a positive integer $$$n$$$. A pair of non-negative integers $$$a, b$$$ is called beautiful if the following conditions hold: $$$a + b = n$$$.  The number $$$a$$$ is a palindrome.$$$^{\text{∗}}$$$  The number $$$b$$$ is divisible by $$$12$$$.You need to find a beautiful pair or report that it does not exist.$$$^{\text{∗}}$$$A number is called a palindrome if and only if it remains the same when its digits (in decimal notation) are written in reverse order. For example, the numbers $$$12321$$$, $$$6776$$$, $$$5$$$, $$$0$$$ are palindromes, while the numbers $$$123$$$ and $$$69$$$ — are not.InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.The only line of each test case contains a single integer $$$n$$$ ($$$1 \leq n \leq 10^{18}$$$).OutputFor each test case, if such $$$a$$$ and $$$b$$$ exist, output $$$a$$$ and $$$b$$$ on a separate line, separated by a space. Otherwise, output $$$-1$$$ on a separate line.If there are several beautiful pairs $$$a, b$$$, you may output any of them.NoteIn the first test case, $$$a = 1$$$ is a palindrome, and $$$b = 0$$$ is divisible by $$$12$$$, and $$$a + b = 1 = n$$$, so the answer satisfies the condition.In the second test case, it can be shown that no pair $$$a, b$$$ is suitable.In the third test case, $$$a = 262$$$ is a palindrome, and $$$b = 48$$$ is divisible by $$$12$$$, and $$$a + b = 310 = n$$$, so the answer satisfies the condition.
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    vector<long long> pal = {0,1,2,3,4,5,6,7,8,9,22,11};
    while(t--){
        long long n;
        cin>>n;
        long long a = pal[n%12];
        if(a>n){
            cout<<-1<<'\n';
            
        } else cout<<a<<' '<<(n-a)<<'\n';
    }
    return 0;
}
