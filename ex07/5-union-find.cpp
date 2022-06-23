#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

class UnionFind {
private: vector<int> parent, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        parent.resize(N);
        for (ll i = 0; i < N; i++) parent[i] = i;
    }
    void unionSet(ll i, ll j) {
        i = findset
    }
    ll findSet(ll i) {
        if (parent[i] == i) return i;
        else return parent[i] = findSet(parent[i]); // path compress
    }

    bool isSameSet(ll i, ll j) {
        return findSet(i) == findSet(j);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    
    // do something
    return 0;
}

