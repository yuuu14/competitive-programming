#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

int dfs(vector<vector<ll>>& g, vector<bool>& visited, ll u, int state) {
    if (state == 3) return state;
    if (u == 0) return state==2 ? 3 : 1;
    if (u == 1) return state==1 ? 3 : 2;
    visited[u] = true;
    int ret = state;
    for (auto v : g[u])
        if (!visited[v])
            ret = dfs(g, visited, v, ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll x_min, x_max, n;
    cin >> x_min >> x_max >> n;
    vector<vector<ll>> c(n+2, vector<ll>(3)), g(n+2);
    for (ll i = 2; i < n+2; i++) {
        for (auto& xyr : c[i]) cin >> xyr;
        if (c[i][0] - c[i][2] < x_min) g[i].push_back(0);
        if (c[i][0] + c[i][2] > x_max) g[i].push_back(1);
        for (ll j = 2; j < i; j++) 
            if ((c[i][0]-c[j][0])*(c[i][0]-c[j][0]) + (c[i][1]-c[j][1])*(c[i][1]-c[j][1]) < 
                (c[i][2]+c[j][2])*(c[i][2]+c[j][2])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    }
    // for (ll i = 2; i < n+2; i++) {
    //     cout << i << ": ";
    //     for (auto& v : g[i]) cout << v << " ";
    //     cout << "\n";
    // }

    vector<bool> visited(n+2, false);
    for (ll i = 2; i < n+2; i++) 
        if (!visited[i] && dfs(g, visited, i, 0)==3) {
            cout << "impossible\n";
            exit(0);
        }

    cout << "possible\n";

    return 0;
}

