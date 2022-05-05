#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll C, N;
    cin >> C >> N;

    // do something
    vector<ll> coins(N, 0);
    for (ll& c : coins) cin >> c;

    vector<ll> dp(C+1, 1e5+1);
    dp[0] = 0;
    for (ll i = 1; i <= C; i++)
        for (ll& coin : coins)
            if (i-coin >= 0) dp[i] = min(dp[i], dp[i-coin]+1);
                
    if (dp[C] != 1e5+1) printf("%lld\n", dp[C]);
    else printf("impossible\n");

    return 0;
}
