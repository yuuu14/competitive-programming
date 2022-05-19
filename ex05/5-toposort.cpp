#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

void dfs(vector<vector<ll>>& g, vector<bool>& visited, deque<ll>& dq, ll v) {
    visited[v] = true;
    for (auto& u : g[v])
        if (!visited[u]) dfs(g, visited, dq, u);
    dq.push_front(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    // adj link
    ll V = 4;
    vector<vector<ll>> g(V);
    g[3].push_back(2);
    g[2].push_back(1);
    g[1].push_back(0);
    g[0].push_back(2);
    
    vector<bool> visited(V, false);
    deque<ll> dq{};
    for (ll i = 0; i < V; i++)
        if (!visited[i])
            dfs(g, visited, dq, i);
    for (auto& elem : dq) cout << elem << " ";
    cout << "\n";
    return 0;
}

