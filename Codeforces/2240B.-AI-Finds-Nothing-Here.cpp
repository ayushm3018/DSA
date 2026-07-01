/*
 * Codeforces: 2240B. AI Finds Nothing Here
 * URL: https://codeforces.com/problemset/problem/2240/B
 * Language: C++20 (GCC 13-64)
 * 
 * B. AI Finds Nothing Heretime limit per test1 secondmemory limit per test256 megabytesinputstandard inputoutputstandard outputMilkcat2009 has a matrix $$$a$$$ with $$$n$$$ rows and $$$m$$$ columns consisting of integers $$$0$$$ and $$$1$$$. The rows are numbered from $$$1$$$ to $$$n$$$, and the columns are numbered from $$$1$$$ to $$$m$$$. The element in the $$$i$$$-th row and $$$j$$$-th column is denoted as $$$a_{i,j}$$$.Milkcat2009's AI scans every single submatrix$$$^{\text{∗}}$$$ of $$$a$$$ consisting of $$$r$$$ rows and $$$c$$$ columns. The AI considers the matrix clean if the bitwise XOR sum of elements in each such submatrix is equal to $$$0$$$.Formally, the matrix $$$a$$$ is valid if and only if for all $$$1 \le i \le n - r + 1$$$ and $$$1 \le j \le m - c + 1$$$: $$$$$$ \bigoplus_{x=i}^{i+r-1} \bigoplus_{y=j}^{j+c-1} a_{x,y} = 0 $$$$$$where $$$\oplus$$$ denotes summation with the bitwise XOR operation.Your task is, given various sets of integers $$$n, m, r, c$$$, to count the number of clean matrices of $$$n$$$ rows and $$$m$$$ columns with respect to scanning dimensions $$$r$$$ and $$$c$$$. Since the answer can be very large, calculate it modulo $$$998\,244\,353$$$.$$$^{\text{∗}}$$$A submatrix of a matrix is obtained by removing some rows (from the beginning and/or end) and/or columns (from the beginning and/or end) from the original matrix.InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.Each test case consists of a single line containing four integers $$$n, m, r, c$$$ ($$$1 \le r \le n \le 10^9$$$, $$$1 \le c \le m \le 10^9$$$), representing the dimensions of the matrix and the dimensions of the scanning area, respectively.OutputFor each test case, output a single integer representing the answer modulo $$$998\,244\,353$$$.NoteFor the first test case. The only element $$$a_{1,1}$$$ must satisfy $$$a_{1,1} = 0$$$. Since $$$a_{1,1}$$$ must be $$$0$$$, there is only $$$1$$$ valid matrix: $$$[0]$$$.For the second test case.The condition requires the XOR sum of every $$$1 \times 2$$$ submatrix to be $$$0$$$. This implies $$$a_{i,j} \oplus a_{i,j+1} = 0$$$, so $$$a_{i,j} = a_{i,j+1}$$$ for all valid $$$i,j$$$. For each row, all elements must be equal. Thus, each row can be either $$$[0, 0, 0]$$$ or $$$[1, 1, 1]$$$. With $$$2$$$ rows, there are $$$2^2 =4$$$ valid matrices.
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

ll modpow(ll a, ll e){
    ll res = 1;
     while(e){
         if(e&1) res= res*a%MOD;
         a=a*a%MOD;
         e>>=1;
     }
     return res;
}
void solve(){
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    
    ll exp = (r-1)*m+(c-1)*n-(r-1)*(c-1);
    cout<<modpow(2, exp)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) solve();
}
