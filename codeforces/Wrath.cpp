/**
 * @file Wrath.cpp
 * @author Arpit Goel
 * @date 2025/03/08 23:30:30
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

void solve() {
    // Your solution code here
    int n;
    cin >> n;
    vector<int> L(n,0);
    for (auto &i:L) cin >> i;
    int pc = 0;
    int ans = n;
    for (int i=n-1;i>-1;i--) {
        if (pc!=0) {
            ans--;
        }
        pc = max(pc-1,L[i]);
    }
    cout << ans << endl;
}

int main() {
    fast_io
    solve();
    return 0;
}

// GitHub: https://github.com/Arpit01Goel