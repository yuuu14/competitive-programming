#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

int main() {
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    
    // #police; #vertices; #edges
    for (ll t = 1, P, V, E; t <= T; t++) {
        cin >> P >> V >> E;
        vector<map<ll, ll>> g(E);
        for (ll i, u, v, w = 0; i < E; i++) {
            cin >> u >> v >> w;
            if (g[u].find(v) == g[u].end() || g[u][v] < w) {
                g[u][v] = w;
                g[v][u] = w;
            }
        }

    }

    return 0;
}

