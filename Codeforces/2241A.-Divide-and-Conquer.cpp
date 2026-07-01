/*
 * Codeforces: 2241A. Divide and Conquer
 * URL: https://codeforces.com/problemset/problem/2241/A
 * Language: C++20 (GCC 13-64)
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        
        if (x >= y && x % y == 0) 
            cout << "YES" << '\n';
         else 
            cout << "NO" << '\n';
        
    }
    return 0;
}
