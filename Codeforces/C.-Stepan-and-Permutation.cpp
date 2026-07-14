/*
 * Codeforces: C. Stepan and Permutation
 * URL: https://codeforces.com/contest/2244/problem/C
 * Language: C++20 (GCC 13-64)
 * 
 * C. Stepan and Permutationtime limit per test2 secondsmemory limit per test256 megabytesinputstandard inputoutputstandard outputStepan found a permutation $$$p$$$ of length $$$n$$$. Of course, he decided to sort it. To make the process more interesting, he chose two positive integers $$$x$$$ and $$$y$$$ $$$(x + y \le n)$$$ and defined a rule for swapping elements.In one move, Stepan can choose two indices $$$i$$$ and $$$j$$$ $$$(1 \le i, j \le n)$$$ and swap the elements $$$p_i$$$ and $$$p_j$$$ if at least one of the following conditions holds:  $$$|i - j| = x$$$  $$$|i - j| = y$$$ Stepan wants to know whether it is possible to sort the permutation in ascending order using any number of such operations. Help him answer this question.InputThe first line contains a single integer $$$t$$$ $$$(1 \le t \le 10^4)$$$ — the number of test cases.The first line of each test case contains three integers $$$n$$$, $$$x$$$, and $$$y$$$ $$$(1 \le x, y \le n \le 2 \cdot 10^5$$$, $$$x + y \le n)$$$ — the length of the array and the numbers chosen by Stepan.The second line of each test case contains $$$n$$$ integers $$$p_i$$$ $$$(1 \le p_i \le n)$$$ — the array $$$p$$$; it is guaranteed that $$$p$$$ is a permutation.It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.OutputFor each test case, output "YES" if it is possible to sort the permutation with the given $$$x$$$ and $$$y$$$, and "NO" otherwise.You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted.
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
      int n,x,y;
      cin>>n>>x>>y;
      vector<int>p(n+1);
      for(int i=1; i<=n; i++){
          cin>>p[i];
      }
      vector<vector<int>>adj(n+1);
      for(int i=1; i<=n; i++){
          if(i+x<=n){
              adj[i].push_back(i+x);
              adj[i+x].push_back(i);
          }
          if(i+y<=n){
              adj[i].push_back(i+y);
              adj[i+y].push_back(i);
          }
      }
      vector<int>comp(n+1, -1);
      int id=0;
      
      for(int i=1; i<=n; i++){
          if(comp[i]!=-1) continue;
          queue<int>q;
          q.push(i);
          comp[i] = id;
          while(!q.empty()){
              int u = q.front();
              q.pop();
              
              for(int v: adj[u]){
                  if(comp[v]==-1){
                      comp[v]=id;
                      q.push(v);
                  }
              }
          }
          id++;
      }
      bool ok = true;
      for(int i=1; i<=n; i++){
          if(comp[i]!=comp[p[i]]){
              ok= false;
              break;
          }
      }
      cout<<(ok?"YES":"NO")<<'\n';
  }
  return 0;
    
}
