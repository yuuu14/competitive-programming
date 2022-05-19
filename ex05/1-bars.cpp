#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E, S, D, res = 0;
    cin >> V >> E >> S >> D;
    S--;
    vector<vector<ll>> g(V);
    vector<int> visited(V, 0);
    for (ll i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<tuple<ll, ll>> q;
    q.push({S, D});

    while (!q.empty()) {
        auto [v, d] = q.front(); q.pop();
        if (d < 0) break;
        if (!visited[v]) {
            res++;
            visited[v] = 1;
            for (ll& u : g[v]) q.push({u, d-1});
        }
    }
    cout << res << "\n";

    return 0;
}

