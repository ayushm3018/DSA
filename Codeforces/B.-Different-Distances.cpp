/*
 * Codeforces: B. Different Distances
 * URL: https://codeforces.com/contest/2233/problem/B
 * Language: C++20 (GCC 13-64)
 * 
 * B. Different Distancestime limit per test2 secondsmemory limit per test512 megabytesinputstandard inputoutputstandard outputConstruct an array of $$$4 \cdot n$$$ integers such that:  each number $$$1, 2, \dots, n$$$ appears in the array exactly $$$4$$$ times;  let $$$p_{x, i}$$$ be the position of the $$$i$$$-th occurrence of number $$$x$$$ in the array; then, for each $$$x$$$ from $$$1$$$ to $$$n$$$, the numbers $$$(p_{x, 2} - p_{x, 1}), (p_{x, 3} - p_{x, 2}), (p_{x, 4} - p_{x, 3})$$$ must be pairwise distinct. For example, for $$$n = 3$$$, one possible array is $$$[1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3]$$$, because:  $$$p_{1, 2} - p_{1, 1} = 1, p_{1, 3} - p_{1, 2} = 2, p_{1, 4} - p_{1, 3} = 3$$$ — all numbers are distinct;  $$$p_{2, 2} - p_{2, 1} = 2, p_{2, 3} - p_{2, 2} = 4, p_{2, 4} - p_{2, 3} = 1$$$ — all numbers are distinct;  $$$p_{3, 2} - p_{3, 1} = 2, p_{3, 3} - p_{3, 2} = 3, p_{3, 4} - p_{3, 3} = 1$$$ — all numbers are distinct. InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 200$$$). The description of the test cases follows.The only line of each test case contains one integer $$$n$$$ ($$$2 \le n \le 200$$$).OutputFor each test case, output the required array. If there are several suitable arrays, output any of them. It can be shown that at least one suitable array always exists under the constraints of the problem.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

    
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }


        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }

  
        for (int i = 2; i <= n; i++) {
            cout << i << ' ';
        }
        cout << 1 << ' ';

 
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }

        cout << '\n';
    }

    return 0;
}
