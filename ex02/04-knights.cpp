#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> twoDvec;

#define debug(x) (cerr << #x << ": " << (x) << endl)

bool bt(twoDvec&, twoDvec&, vector<ll>&, vector<ll>&, twoDvec&);
bool dfs(twoDvec&, twoDvec&, vector<ll>&, vector<ll>&, vector<ll>&, ll);

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;

    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    // do something
    // 
    twoDvec rect(n, vector<ll>(4, 0)), area{};
    for (ll i = 0, a; i < n; i++) {
        for (auto &r : rect[i]) { cin >> r; r--; }
        a = (rect[i][2] - rect[i][0]) * (rect[i][3] - rect[i][1]); 
        area.push_back(vector<ll>{a, rect[i][0], rect[i][1], i});
    }
    sort(area.begin(), area.end());
    vector<ll> ord(n, 0);
    for (ll i = 0; i < n; i++) ord[i] = area[i][3];
        
    // divide area into 2 parts, if either part fail then fail
    twoDvec pos(n, vector<ll>(2, 0)), subset(n, vector<ll>(2, 0));
    vector<ll> row(n, 0), col(n, 0);
    vector<ll> tmp(n*n*n*n, 0);
    iota(tmp.begin(), tmp.end(), 1);
    for (auto& t : tmp) t++;
    // do {} while (next_permutation(tmp.begin(), tmp.end()));
    // for (ll i = 0; i < n; i++) subset[i][1] = i;

    // if (bt(rect, pos, row, col, subset))
    //     for (auto &p : pos) printf("%lld %lld\n", p[0], p[1]);
    // else printf("NI\n");
   
    // if (dfs(rect, pos, row, col, ord, 0)) 
    //     for (auto &p : pos) printf("%lld %lld\n", p[0], p[1]);
    // else cout << "NI\n";

    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, milli> ms_double = t2 - t1;
    // cout << ms_int.count() << "ms\n";
    cout << ms_double.count() << "ms\n";

    return 0;
}   

bool dfs(twoDvec& rect, twoDvec& pos, vector<ll>& row, vector<ll>& col, vector<ll>& ord, ll it) {
    if (it == ll(rect.size())) return true;
    ll cur_it = ord[it];
    for (ll i = rect[cur_it][0]; i <= rect[cur_it][2]; i++) {
        if (row[i]) continue;
        row[i] = 1;
        for (ll j = rect[cur_it][1]; j <= rect[cur_it][3]; j++) {
            if (col[j]) continue;
            col[j] = 1;
            pos[cur_it][0] = i + 1;
            pos[cur_it][1] = j + 1;
            if (dfs(rect, pos, row, col, ord, it+1)) return true;
            else col[j] = 0;
        }
        row[i] = 0;
    }
    return false;
}

bool bt(twoDvec& rect, twoDvec& pos, vector<ll>& row, vector<ll>& col, twoDvec& subset) {
    ll n = subset.size(), i = 0;
    if (n == 1) {
        // check rect[subset[0][1]] available?
        vector<ll> area(rect[subset[0][1]]);
        for (ll i = area[0]; i <= area[2]; i++)
            for (ll j = area[1]; j <= area[3]; j++) 
                if (row[i]+col[j] == 0) {
                    pos[subset[0][1]][0] = i+1;
                    pos[subset[0][1]][1] = j+1;
                    row[i] = 1;
                    col[j] = 1;
                    return true;
                }
        return false;
    }
    for (ll i = (ll)ceil(n/2); i < n; i++) subset[i][0] = 1;
    do {
        // if (n%2 == 0 && n/2 == i) break;
        twoDvec sub1{}, sub2{};
        for (auto &sub : subset) 
            if (sub[0]) sub2.push_back(vector<ll>{0, sub[1]});
            else sub1.push_back(sub);
        if (!bt(rect, pos, row, col, sub1)) return false;
        if (!bt(rect, pos, row, col, sub2)) return false;
        else return true;

    } while (next_permutation(subset.begin(), subset.end(), [](const vector<ll>& a, vector<ll>& b) {
        return a[0] < b[0];
    }));
    return true;
}

/*
3  r=012 021 102 120 201 210
1 1 2 2
2 2 3 3
1 3 2 3
2  r=01 r=10
1 1 2 1   1/2  2  divide into 2 part
1 1 1 2   1    0
*/
// for i in n: for j in n
// 22 23 32 33
// 13 23