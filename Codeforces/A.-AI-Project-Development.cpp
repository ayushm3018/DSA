/*
 * Codeforces: A. AI Project Development
 * URL: https://codeforces.com/contest/2233/problem/A
 * Language: C++20 (GCC 13-64)
 * 
 * A. AI Project Developmenttime limit per test2 secondsmemory limit per test512 megabytesinputstandard inputoutputstandard outputMaxim and Nikita are working together on a project consisting of $$$n$$$ lines of code.Maxim starts working immediately and writes at a speed of $$$x$$$ lines per hour until the very end.Nikita has two options:   not use AI and write from the very beginning at a speed of $$$y$$$ lines per hour;  spend $$$z$$$ hours first setting up an AI agent, writing nothing during that time, and then write at a speed of $$$10 \cdot y$$$ lines per hour. Nikita makes this choice before work begins and does not change it later.While Nikita is setting up the AI, he does not write any code at all, but Maxim continues working at the speed of $$$x$$$ lines per hour.The project is considered completed as soon as Maxim and Nikita together have written at least $$$n$$$ lines of code. If the project can be completed before the AI setup ends, then the work ends at that moment.Time is measured using full hours: if a project is completed in the middle of an hour, this hour is counted fully.Nikita chooses whether to use AI or not.Determine the minimum number of full hours after which the project will be completed.InputEach test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows.The only line of each test case contains four integers $$$n$$$, $$$x$$$, $$$y$$$, and $$$z$$$ ($$$1 \le n, x, y, z \le 10\,000$$$) — the number of lines in the project, Maxim's speed, Nikita's speed without AI, and the AI setup time, respectively.OutputFor each test case, output one integer — the minimum number of full hours after which the project will be completed if Nikita acts optimally.NoteIn the first example, without using AI, Nikita and Maxim will write $$$2$$$ lines of code in $$$1$$$ hour, and since the project requires only $$$1$$$ line to finish, it will be completed in $$$1$$$ hour.In the fourth example, Nikita spends the first hour setting up the AI, while Maxim writes $$$10$$$ lines during that time, and then during the next hour $$$10 + 9 \cdot 10 = 100$$$ lines of code are written, so the whole project can be completed in $$$2$$$ hours.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;

        long long noAI = (n + (x + y) - 1) / (x + y);

        long long withAI;

        if (x * z >= n) {
            withAI = (n + x - 1) / x;
        } else {
            long long rem = n - x * z;
            withAI = z + (rem + (x + 10 * y) - 1) / (x + 10 * y);
        }

        cout << min(noAI, withAI) << '\n';
    }

    return 0;
}
