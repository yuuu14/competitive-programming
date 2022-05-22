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
    ll V, E;
    vector<vector<ll>> g(V);

    vector<ll> indegree;
    deque<ll> cycle;

    for (ll i = 0; i < V; i++)
        if (indegree[i] != g[i].size()) {
            cout << "impossible\n";
            exit(0);
        }
    
    find_cycle(g, cycle, 0); // start from anywhere 
    // check whether graph is disconnected
    if (cycle.size() != E+1) {
        cout << "impossible\n";
        exit(0);
    }
    for (auto& v : cycle) cout << v << " ";
    cout << "\n";

    return 0;
}

