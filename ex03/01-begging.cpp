#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;

    // do something
    vector<ll> track(n, 0), dp(n, 0);
    ll M = 0;
    for (ll i = 0, pos = -1, tmp, w; i < n; i++) {
        cin >> w;
        tmp = 0;
        if (i-m >= 0) tmp = dp[i-m];
        if (w+tmp > M) {
            pos = i;
            M = w + tmp;
        } 
        track[i] = pos;
        dp[i] = M;
    }
    vector<ll> res;
    for (ll i = n-1; i >= 0;) {
        if (track[i] != i) i = track[i];
        else {
            res.push_back(i);
            i -= m;
        }
    }
    printf("%lld %lld\n", M, (ll)res.size());
    for (ll i = (ll)res.size()-1; i >= 0; i--)
        if (i != 0) printf("%lld ", res[i]+1);
        else printf("%lld\n", res[i]+1);
    // for (auto rit = res.rbegin(); ; rit++) {
    //     printf("%lld", (*rit)+1);
    //     if (rit+1 != res.rend()) printf(" ");
    //     else { printf("\n"); break; }
    // }

    return 0;
}
