/*
 * Codeforces: A. Iskander and Drawings
 * URL: https://codeforces.com/contest/2244/problem/A
 * Language: C++20 (GCC 13-64)
 * 
 * A. Iskander and Drawingstime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputDuring a geometry lesson, Iskander got very bored, so he decided to draw in Yura's notebook. To do this, he took a row and drew horizontal lines on it. Some lines are long, some are short, and some parts of the page remain empty.The page is represented by a string $$$s$$$, where the character '*' denotes an empty part of the paper, and the character '#' denotes one centimeter of a drawn line. A continuous sequence of '#' characters forms a single line.Yura decided to erase all the lines and made Iskander help him: they will erase one of the lines from both ends simultaneously.  Each second, Iskander erases $$$1$$$ centimeter from the right end of the line, and Yura erases $$$1$$$ centimeter from the left end.  If the current length of the line is $$$1$$$ or $$$2$$$ centimeters, then in the next second it is erased completely, and the process ends. Yura wants to choose a line so that, together with Iskander, they erase it for as long as possible. Help him determine this maximum time. If there are no lines on the page, the answer is $$$0$$$ seconds.InputThe first line contains a single integer $$$t$$$ ($$$1 \le t \le 2500$$$) — the number of test cases.The first line of each test case contains an integer $$$n$$$ ($$$1 \le n \le 10$$$) — the length of the string $$$s$$$.The second line of each test case contains a string $$$s$$$ of length $$$n$$$, consisting of characters '#' and '*'.OutputFor each test case, output a single integer — the maximum time required to erase a line.
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
    int t;
    cin>>t;
    while(t--){
        int n, cnt = 0, ans=0;
        ;
        cin>>n;
        string s;
        cin>>s;
        for(char c: s){
            if(c=='#') cnt++;
            else {
                ans = max(ans, (cnt+1)/2);
                cnt=0;
            } 
        }
        ans=max(ans, (cnt+1)/2);
        cout<<ans<<endl;
        
    }
    return 0;
}
