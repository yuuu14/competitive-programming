#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

int main() {
    ios_base::sync_with_stdio(false);
    ll V, start = 0;
    vector<vector<tuple<ll, ll>>> g(V);

    vector<ll> dist(V, INF);
    dist[start] = 0;
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, greater<tuple<ll, ll>>> pq{};
    pq.push({start, 0});
    while(!pq.empty()) {
        auto [v, d] = pq.top(); pq.pop();
        if (d > dist[v]) continue; // lazy deletion
        for (auto& [u, w] : g[v]) 
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({u, dist[u]});
            }
    }


    // do something
    return 0;
}

