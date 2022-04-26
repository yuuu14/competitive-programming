#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<ll> colony(n, 0);
    for (ll &c : colony) {
        cin >> c;
        c %= 2;
    }
    
    // get sqrt array
    ll size = (ll)ceil(sqrt((long double)n));
    ll block_size = (ll)ceil((long double)n / size);
    vector<ll> block(block_size, 0);
    // counting 
    for (ll i = 0; i < n; i++) {
        if (colony[i] % 2) block[i/size]++;
    }
    
    // do something
    while (q--) {
        ll a, b;
        char type;
        cin >> type >> a >> b;
        if (type == 'U') {
            a--;
            if (colony[a]%2 == b%2) continue;
            if (b % 2) block[a/size]++;
            else block[a/size]--;
            colony[a] = b%2;
        } else {
            a--; b--;
            ll i = ceil((long double)a / size), j = b/size - 1, res = 0;
            if (i > j) for (ll k = a; k <= b; k++) res += colony[k];
            else {
                for (ll k = a; k < i*size; k++) res += colony[k];
                for (ll k = i; k <= j; k++) res += block[k];
                for (ll k = (j+1) * size; k <= b; k++) res += colony[k];
            }
            cout << res << "\n";
        }

    }

    return 0;
}