/*
 * Codeforces: A. Euclid, Sequence and Two Numbers
 * URL: https://codeforces.com/contest/2234/problem/A
 * Language: C++20 (GCC 13-64)
 * 
 * A. Euclid, Sequence and Two Numberstime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputWe define a Euclid algorithm sequence of length $$$k$$$ ($$$k \geq 2$$$) for two positive integers $$$x \geq y$$$ as the following sequence of positive integers: $$$a_1, a_2, \ldots, a_k$$$, where $$$a_1 = x$$$, $$$a_2 = y$$$, and for any $$$i$$$ ($$$1 \leq i \leq k - 2$$$), the equality $$$a_{i + 2} = (a_i \bmod a_{i + 1})$$$ holds$$$^{\text{∗}}$$$.For example, for $$$x = 13, y = 8, k = 4$$$, the corresponding Euclid algorithm sequence is $$$a = [13, 8, 5, 3]$$$. ($$$a_3 = 13 \bmod 8 = 5$$$, $$$a_4 = 8 \bmod 5 = 3$$$).You are given a sequence $$$b_1, b_2, \ldots, b_n$$$. You need to determine whether it is possible to permute its elements so that it becomes a Euclid algorithm sequence for some two positive integers $$$x \geq y$$$.$$$^{\text{∗}}$$$$$$x \bmod y$$$ denotes the remainder when $$$x$$$ is divided by $$$y$$$.InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 500$$$). The description of the test cases follows.The first line of each test case contains an integer $$$n$$$ ($$$2 \leq n \leq 100$$$) — the size of the sequence.The second line of each test case contains $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$1 \leq b_i \leq 10^9$$$) — the sequence $$$b$$$.OutputFor each test case, if it is possible to permute the elements of sequence $$$b$$$ so that there exists a suitable pair of positive integers $$$x \geq y$$$, output $$$x, y$$$ on a separate line. Otherwise, output $$$-1$$$ on a separate line.If there are several suitable pairs $$$x, y$$$, you may output any of them.NoteIn the first test case, the pair ($$$1, 1$$$) is suitable: for $$$x = 1, y = 1, k = 2$$$, $$$a_1 = x = 1, a_2 = y = 1$$$, and the sequence $$$a = [1, 1] = b$$$ is obtained.In the third test case, it can be shown that no suitable pair ($$$x, y$$$) exists.In the fourth test case, the pair ($$$6, 4$$$) is suitable: for $$$x = 6, y = 4, k = 3$$$, $$$a_1 = x = 6, a_2 = y = 4, a_3 = (a_1 \bmod a_2) = (6 \bmod 4) = 2$$$, and the sequence $$$a = [6, 4, 2] = b$$$ is obtained.
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> b(n);
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        sort(b.begin(), b.end(), greater<long long>());
        bool ok = true;
        for (int i=2; i<n; i++){
            if(b[i]!=b[i-2]%b[i-1]){
                ok = false;
                break;
            }
        }
        if(ok) cout<<b[0]<<" "<<b[1]<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}
