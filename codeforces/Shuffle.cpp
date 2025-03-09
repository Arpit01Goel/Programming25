/**
 * @file Shuffle.cpp
 * @author Arpit Goel
 * @date 2025/03/08 23:49:11
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

void solve() {
    // Your solution code here
    int n,c,m;
    cin >> n >> c >> m;
    int a=c,b=c, l,r;
    for (int i=0;i<m;i++){
    cin >> l >> r ;
    if (r<a || l>b) {continue;}
    else {
        a=min(a,l);
        b = max(b,r);
    }
    }
    cout << b-a+1 << endl;
}

int main() {
    fast_io
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

// GitHub: https://github.com/Arpit01Goel