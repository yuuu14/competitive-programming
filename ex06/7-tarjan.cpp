#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();
const ll UNVISITED = -1;

void dfs(vector<vector<ll>>&g, vector<ll>& dfs_num, vector<ll>& dfs_min, vector<bool>& on_stack, 
         vector<ll>& eq_class, stack<ll>& st, ll& dfs_counter, ll& num_class, ll u) {
    dfs_min[u] = dfs_num[u] = dfs_counter++;
    st.push(u);
    on_stack[u] = true;
    for (auto& v : g[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs(g, dfs_num, dfs_min, on_stack, eq_class, st, dfs_counter, num_class, v);
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
    ll V;
    vector<vector<ll>> g(V);
    vector<ll> eq_class(V, 0);

    stack<ll> st;
    ll dfs_counter = 0, num_class = 0;
    vector<ll> dfs_num(V, UNVISITED), dfs_min(V, UNVISITED);
    vector<bool> on_stack(V, false);

    for (ll i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED)
            dfs(g, dfs_num, dfs_min, on_stack, eq_class, st, dfs_counter, num_class, i);
    vector<vector<ll>> dag(num_class);
    for (ll v = 0; v < V; v++) 
        for (auto& u : g[v]) {
            if (find(dag[eq_class[v]].begin(), dag[eq_class[v]].end(), eq_class[u]) 
                != dag[eq_class[v]].end())
                dag[eq_class[v]].push_back(eq_class[u]);
        }

    return 0;
}

