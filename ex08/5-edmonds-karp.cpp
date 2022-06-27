#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

vector<vector<ll>> cap; // adj matrix
vector<vector<ll>> g; // adj list
vector<ll> parent;

void bfs(ll s) {
    parent.assign(g.size(), -1);
    parent[s] = -2; // visited

    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll v : g[u])
            if (parent[v] == -1 && cap[u][v] > 0) {
                q.push(v); 
                parent[v] = u;
            }
    }
}

ll maxFlow(ll s, ll t) {
    ll totalFlow = 0, u;
    while (true) {
        bfs(s);
        if (parent[t] == -1) break; // unreachable
        ll bottleneck = INF;
        u = t;
        while (u != s) {
            ll v = parent[u];
            bottleneck = min(bottleneck, cap[v][u]);
            u = v;
        }
        u = t; // update cap along path
        while (u != s) {
            ll v = parent[u];
            cap[v][u] -= bottleneck;
            cap[u][v] += bottleneck;
            u = v;
        }
        totalFlow += bottleneck;
    }
    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll s, t, V, E;
    cin >> V >> E >> s >> t;
    g.resize(V);
    cap.assign(V, vector<ll>(V, 0));
    
    for (ll i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += w;
    }
    ll out = maxFlow(s-1, t-1);
    cout << out << "\n";
    
    return 0;
}

