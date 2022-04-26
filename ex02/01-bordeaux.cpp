#include <bits/stdc++.h>
// #include <algorithm>


using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> trade(n, vector<ll>(2, 0));
    for (ll i = 0; i < n; i++)
        cin >> trade[i][0] >> trade[i][1];
    
    // d, v, only consider d < v
    sort(trade.begin(), trade.end());
    ll borrow{0}, cur{0};
    for (ll i = 0; i < n; i++) {
        if (trade[i][0] >= trade[i][1]) continue;
        if (cur < trade[i][0]) { 
            borrow += trade[i][0] - cur; 
            cur = trade[i][0];
        }
        cur += trade[i][1] - trade[i][0];
        debug(cur);
    }
    printf("%lld %lld\n", borrow, cur-borrow);

    
    return 0;
}