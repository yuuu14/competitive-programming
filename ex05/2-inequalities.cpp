#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

bool dfs(vector<vector<ll>>& g, vector<bool>& visited, vector<bool>& stack, deque<ll>& dq, ll v) {
    visited[v] = true;
    stack[v] = true;
    for (auto& u : g[v]) {
        if ((!visited[u] && dfs(g, visited, stack, dq, u)) || stack[u])
            return true;
    }
    stack[v] = false;
    dq.push_front(v);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll t, V = 0;
    cin >> t;
    map<string, ll> vars;
    map<ll, string> ids;
    vector<vector<ll>> g{}; // larger point to smaller
    for (ll i = 0, j, k; i < t; i++) {
        string a, s, b;
        cin >> a >> s >> b;
        if (vars.find(a) == vars.end()) { 
            j = V++; 
            vars[a] = j; 
            ids[j] = a; 
            g.push_back(vector<ll>{});
        } else j = vars[a];
        if (vars.find(b) == vars.end()) { 
            k = V++; 
            vars[b] = k; 
            ids[k] = b;
            g.push_back(vector<ll>{});
        } else k = vars[b];
        if (s == ">") g[j].push_back(k);
        else g[k].push_back(j);
    }

    // check circle + toposort
    vector<bool> visited(V, false), stack(V, false);
    deque<ll> dq{};
    bool exist = true;
    for (ll i = 0; i < V && exist; i++) 
        if (!visited[i] && dfs(g, visited, stack, dq, i))
            exist = false;
    if (!exist) { cout << "impossible\n"; return 0; }
    cout << "possible\n";
    for (auto it = dq.begin(); it != dq.end(); it++) {
        if (it != dq.end()-1) cout << ids[*it] << " ";
        else cout << ids[*it] << "\n";
    }
    return 0;
}

