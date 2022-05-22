#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();
const ll UNVISITED = -1;
static ll dfs_counter = 0, num_class = 0;

void dfs(vector<vector<ll>>&g, vector<ll>& dfs_num, vector<ll>& dfs_min, 
         vector<bool>& on_stack, vector<ll>& eq_class, stack<ll>& st, ll u) {
    dfs_min[u] = dfs_num[u] = dfs_counter++;
    st.push(u);
    on_stack[u] = true;
    for (auto& v : g[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs(g, dfs_num, dfs_min, on_stack, eq_class, st, v);
            dfs_min[u] = min(dfs_min[u], dfs_min[v]);
        } else if (on_stack[v]) // only on_stack can use back edge
            dfs_min[u] = min(dfs_min[u], dfs_num[v]);
    }
    if (dfs_min[u] == dfs_num[u]) {
        ll v = -1;
        while (v != u) {
            v = st.top(); st.pop();
            on_stack[v] = false;
            eq_class[v] = num_class;
        }
        num_class++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E; cin >> V >> E;
    vector<ll> gold(V, 0);
    for (auto& g : gold) cin >> g;
    vector<vector<ll>> g(V);
    for (ll i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    stack<ll> st;
    vector<ll> eq_class(V, 0);
    vector<ll> dfs_num(V, UNVISITED), dfs_min(V, UNVISITED);
    vector<bool> on_stack(V, false);

    for (ll i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED)
            dfs(g, dfs_num, dfs_min, on_stack, eq_class, st, i);

    vector<ll> eq_gold(num_class, 0), cur_max(num_class, 0);
    for (ll i = 0; i < V; i++)
        eq_gold[eq_class[i]] += gold[i];

    vector<set<ll>> dag(num_class);
    for (ll v = 0; v < V; v++) 
        for (auto& u : g[v]) {
            if (eq_class[u] == eq_class[v]) continue;
            dag[eq_class[v]].emplace(eq_class[u]);
        }
    // for (ll i = 0; i < num_class; i++) {
    //     cout << i << ": ";
    //     for (auto& v : dag[i]) cout << v << " ";
    //     cout << "gold: " << eq_gold[i] << "\n";
    // }

    // topo. order: n-1, n-2, ..., 1, 0
    ll res = 0;
    for (ll u = num_class-1; u >= 0; u--) {
        cur_max[u] += eq_gold[u];
        res = max(res, cur_max[u]);
        for (auto& v : dag[u]) {
            cur_max[v] = max(cur_max[v], cur_max[u]);
        }
    }
    cout << res << "\n";
    
    return 0;
}

