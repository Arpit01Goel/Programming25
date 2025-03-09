/**
 * @file Eugeny and Play List.cpp
 * @author Arpit Goel
 * @date 2025/03/08 23:06:12
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

void solve() {
    // Your solution code here
    int n,m;
    cin >> n >> m;
    vector<int> t(n,0),c(n,0);
    for (int i=0;i<n;i++) {
        cin >> c[i];
        cin >> t[i];
    }
    vector<int> lk(m,0);
    for (auto &i:lk) cin >> i;
    vector<ll> prefix(n,0);
    prefix[0] = t[0]*c[0];
    for (int i=1;i<n;i++) {
        prefix[i] = t[i]*c[i] + prefix[i-1];
    }
    int l = 0,r=n-1,ans = 0;
    for (int i=0;i<m;i++) {
        //use binary search from last answer to n-1
        l = ans;
        r = n-1;
        
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (prefix[mid]==lk[i]) {
                ans = mid;
                break;
            }
            if (prefix[mid]<lk[i] && lk[i]<prefix[mid+1]) {
                ans = mid+1;
                break;
            }
            if (prefix[mid]>lk[i]) {
                r = mid-1;
            }
            if (prefix[mid]<lk[i]) {
                l = mid+1;
            }
        }
        cout << ans+1 << endl;
    }
}

int main() {
    fast_io
    
        solve();
    
    return 0;
}

// GitHub: https://github.com/Arpit01Goel