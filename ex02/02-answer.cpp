#include <bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n, t;
    cin >> n >> t;

    vector<ll> n1(n/2, 0), n2(n - n/2, 0);
    for (ll &num : n1)
        cin >> num;
    for (ll &num : n2)
        cin >> num;
    
    // meet in the middle
    ll N1 = (ll)1 << n1.size(), N2= (ll)1 << n2.size(), res = 0;
    map<ll, ll> subsum;
    for (ll i = 0, sum; i < N2; i++) {
        sum = 0;
        for (ll j = 0; j < n2.size(); j++)
            if (i & (ll)1 << j) sum += n2[j];
        subsum[sum]++;
    }
    for (ll i = 0, t1, t2; i < N1; i++) {
        t1 = 0, t2 = 0;
        for (ll j = 0; j < n1.size(); j++) 
            if (i & (ll)1 << j) t1 += n1[j];
        t2 = t - t1;
        res += subsum[t2];
    }

    cout << res << "\n";
    return 0;
}