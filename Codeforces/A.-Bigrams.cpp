/*
 * Codeforces: A. Bigrams
 * URL: https://codeforces.com/contest/2242/problem/A
 * Language: C++20 (GCC 13-64)
 * 
 * A. Bigramstime limit per test2 secondsmemory limit per test512 megabytesinputstandard inputoutputstandard outputA bigram in a string is a pair of adjacent characters. For example, the string helloello contains $$$8$$$ bigrams: he, el, ll, lo, oe, el, ll, lo.Monocarp has cards with letters: $$$c_1$$$ cards with the letter a, $$$c_2$$$ cards with the letter b, ..., $$$c_k$$$ cards with the $$$k$$$-th letter of the Latin alphabet. He wants to make a string from these cards, using each card exactly once. The resulting string must contain at least two equal bigrams. The order of characters in each bigram matters; for example, the string aba does not have two equal bigrams.Determine whether it is possible to make a string that satisfies these requirements.InputThe first line contains one integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.Each test case consists of two lines:  the first line contains one integer $$$k$$$ ($$$1 \le k \le 10$$$);  the second line contains $$$k$$$ integers $$$c_1, c_2, \dots, c_k$$$ ($$$1 \le c_i \le 10^8$$$), where $$$c_i$$$ is the number of cards with the $$$i$$$-th letter of the Latin alphabet. OutputFor each test case, output YES if it is possible to construct a string satisfying the condition, or NO otherwise.Each letter can be output in any case. For example, yes, Yes, yEs will be recognized as a positive answer.NoteIn the first example, you can only make the string a, which contains no bigrams.In the second example, you can make the string aaa, which contains two bigrams aa.In the third example, you can make the string aaaa, which contains three bigrams aa.In the fourth example, you can make the string aab, aba, or baa. None of these strings contains two equal bigrams.In the fifth example, you can make the string aabab, which contains two bigrams ab.
 */

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        bool ok = false;
        int cnt = 0;
        for(int i=0; i<k; i++){
            int x;
            cin>>x;
            if(x>=3) ok = true;
            if(x>=2) cnt++;
        }
        if(ok || cnt>=2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
