#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);

    // do something
    ll h, w, H, lgth = 0;
    cin >> h >> w;
    vector<vector<ll>> tray(h+1, vector<ll>(w+1, 1));
    vector<ll> res(4, -1);
    for (ll i = 1; i <= h; i++) tray[i][0] += tray[i-1][0];
    for (ll j = 1; j <= w; j++) tray[0][j] += tray[0][j-1];

    for (ll i = 1; i <= h; i++) 
        for (ll j = 1; j <= w; j++) {
            cin >> tray[i][j];
            tray[i][j] += tray[i-1][j] + tray[i][j-1] - tray[i-1][j-1];
        }

    cin >> H;
    for (ll i = H; i <= h; i++) {
        for (ll j = 1, cur = 0; j <= w; j++) 
            if (!(tray[i][j] - tray[i][j-1] - tray[i-H][j] + tray[i-H][j-1])) {
                cur++;
                // printf("%lld %lld %lld %lld\n", i, j, cur, lgth);
                if (i == w && cur > lgth) {
                    lgth = cur;
                    res[0] = i-H+1;
                    res[2] = i;
                    res[3] = j;
                } 
            } else {
                if (cur > lgth) {
                    lgth = cur;
                    res[0] = i-H+1;
                    res[2] = i;
                    res[3] = j-1;
                }
                cur = 0;
            }
    }
    if (lgth) res[1] = res[3]-lgth+1;
    printf("%lld %lld %lld %lld\n", res[0], res[1], res[2], res[3]);

    return 0;
}



