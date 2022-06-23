#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

int main() {
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    map<string, ll> name2id;
    vector<string> names;
    for (ll i = 0; i < n; i++) {
        string name;
        cin >> name;
        name2id[name] = i;
        names.push_back(name);
    }
    vector<vector<int>> g(n);
    
    
    // do something
    return 0;
}

