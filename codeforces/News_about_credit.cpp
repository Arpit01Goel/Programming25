/**
 * @file News_about_credit.cpp
 * @author Arpit Goel
 * @date 2025/03/08 22:07:06
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;



int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (auto &i:a) cin >> i;

    auto comp = [](pair<int,int> a, pair<int,int> b) {
        if (a.first==0) return true;
        if (b.first==0) return false;
        return b.second < a.second;
    };

    vector<pair<int,int> > data;

    for (int i=0;i<n;i++) {
        data.push_back({i,a[i]});
    }
    sort(data.begin(),data.end(),comp);
    // for (auto i:data) {
    //     cout << i.first << "," << i.second <<"\t";
    // }cout << endl;
    vector<pair<int,int>> vec;
    queue<int> que;
    for (auto i:data) {
        que.push(i.first);
    }
    vector<int> visited(n,0);
    bool flag = true;
    visited[0]=1;
    while (que.empty()!=true) {
        int p = que.front();
        if (visited[p]==0) {flag = false;}
        for (int i=1;i<=a[p];i++) {
            if (data.size()==1) break;
            vec.push_back({p,data[1].first});
            visited[data[1].first]=1;
            que.push(data[1].first);
            data.erase(data.begin()+1);
        }
        if (data.size()==1) break;
        que.pop();
    }
    
    if (data.size()!=1 || flag == false) {cout << -1 << endl;}
    else {
        cout << vec.size() << endl;
        for (auto i:vec) {
            cout << ( (i.first)+1 )<< " " << ((i.second)+ 1 )<< endl;
        }
    }

    return 0;
}

// GitHub: https://github.com/Arpit01Goel