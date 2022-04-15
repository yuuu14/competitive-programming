#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    vector<vector<ll>> joy(11, vector<ll>(11, 0));
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++) 
            cin >> joy[i][j];

    ll mxm = 0;
    vector<int> perm(11);
    iota(perm.begin(), perm.end(), 0);
    do {
        ll sum = 0;
        for (int i = 0; i < 11; i++)
            sum += joy[i][perm[i]];
        mxm = max(mxm, sum);
    } while (next_permutation(perm.begin(), perm.end()));
    printf("%lld\n", mxm);

    return 0;
}