#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

void find_cycle(vector<vector<ll>>& g, deque<ll>& cycle, ll u) {
    while (g[u].size()) {
        ll v = g[u].back();
        g[u].pop_back();
        find_cycle(g, cycle, v);
    }
    cycle.push_front(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E; cin >> V >> E;
    vector<vector<ll>> g(V);
    vector<ll> indegree(V, 0);
    for (ll i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        indegree[v]++;
    }

    for (ll i = 0; i < V; i++)
        if (((i == 0 || i == V-1) && indegree[i] == (ll)g[i].size()) || 
            (0 < i && i < V-1 && indegree[i] != (ll)g[i].size())) {
            cout << "impossible\n";
            exit(0);
        }
    
    deque<ll> cycle;
    find_cycle(g, cycle, 0); // start from anywhere 
    // check whether graph is disconnected
    if ((ll)cycle.size() != E+1) {
        cout << "impossible\n";
        exit(0);
    }
    cout << "possible\n";

    return 0;
}

