#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;

    // do something
    vector<ll> seq(n, 0), track_end(n, 0);
    for (ll& s : seq) cin >> s;
    
    ll lgth = 0;
    for (ll& s : seq) {
        auto low = lower_bound(track_end.begin(), track_end.begin()+lgth, s);
        if (*low == s) continue;
        if (low-track_end.begin() < lgth) track_end[low-track_end.begin()] = s;
        else {
            track_end[lgth] = s;
            lgth++;
        }
    }
    printf("%lld\n", lgth);

    return 0;
}
