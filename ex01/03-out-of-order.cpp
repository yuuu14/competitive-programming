#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> stamps(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> stamps[i];
    
    // copy and sort
    vector<ll> sorted_stamps(stamps);
    sort(sorted_stamps.begin(), sorted_stamps.end());
    // compare diff pos
    vector<ll> pos(2, -1);
    for (ll i = 0; i < n; i++) {
        if (stamps[i] != sorted_stamps[i]) {
            if (pos[0] == -1) pos[0] = i;
            else if (pos[1] == -1) pos[1] = i;
            else { cout << "impossible\n"; return 0; }
        }
    }
    printf("%lld %lld\n", pos[0]+1, pos[1]+1);
    
    /*
    ll fst = -1, lst = n-1;
    for (ll i = 0; i < n-1; i++) {
        if (stamps[i] > stamps[i+1]) {
            if (fst == -1) fst = i;
            else if (lst == n-1) lst = i+1;
            else {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    // compare [fst] >= [lst-1] and [lst] <= [fst+1]
    // 2 5 4 3 4
    if (fst == -1 ||
        stamps[fst] < stamps[lst-1] || stamps[lst] > stamps[fst+1] || 
        fst > 0 && stamps[lst] < stamps[fst-1] || 
        lst < n-1 && stamps[fst] > stamps[lst+1])
        cout << "impossible\n";
    else
        cout << fst+1 << " " << lst+1 << "\n";
    */
    return 0;
}

/*

1 2 3 5 7 8 9
9 2 3 5 7 8 1
*/