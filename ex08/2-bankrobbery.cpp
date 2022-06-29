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
    ll T;
    cin >> T;
    for (ll t = 1, P, V, E; t <= T; t++) {
        cin >> P >> V >> E;
        // cout << P << " " << V << " " << E << "\n";
        g.assign(V, vector<ll>{});
        cap.assign(V, vector<ll>(V, 0));

        for (ll i = 0, u, v, w; i < E; i++) {
            cin >> u >> v >> w;
            u--, v--;
            if (u == v) continue;
            if (find(g[u].begin(), g[u].end(), v) == g[u].end()) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
            cap[u][v] += w;
        }
        // for (ll i = 0; i < V; i++) {
        //     cout << i << " -> ";
        //     if (!g[i].empty())
        //         for (auto v : g[i]) cout << v << " ";
        //     cout << "\n";
        // }
        // cout << "Case #" << t << "\n";
        
        ll out = maxFlow(0, V-1);
        string yes = (P>=out && out)? "yes" : "no";
        cout << "Case #" << t << ": " << yes << "\n";
    }
    
    return 0;
}

