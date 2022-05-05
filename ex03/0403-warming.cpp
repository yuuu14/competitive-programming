#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;

    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    // do something
    vector<ll> seq(n, 0), track_end(n, 0), track_rvs(n, 0), track_max(n, 0), track_lgth(n, 0);
    vector<vector<ll>> dp{};
    vector<ll> lis{}, lis_bwd(n, 0);
    for (ll& s : seq) cin >> s;
    
    ll lgth = 0, res = 0;
    for (auto s = seq.begin(); s != seq.end(); s++) {
        auto low = lower_bound(lis.begin(), lis.begin()+lgth, *s);
        if (low-lis.begin() < lgth) lis[low-lis.begin()] = *s;
        else { lis.push_back(*s); lgth++; }
        dp.emplace_back(lis);
        // dp[s-seq.begin()] = lis;
    }
    res = lgth; lgth = 0;
    for (auto rit = seq.rbegin(); rit != seq.rend(); rit++) {
        auto upp = upper_bound(lis_bwd.end()-lgth, lis_bwd.end(), *rit);
        if (lis_bwd.end()-upp < lgth) lis_bwd[n-1-(lis_bwd.end()-upp)] = *rit;
        else { lis_bwd[n-1-lgth] = *rit; lgth++; }

        if (rit == seq.rend()-1) { res = max(res, lgth); break; }
        for (ll i = dp[n-2-(rit-seq.rbegin())].size()-1, tmp = 0; i >= 0; i--) {
            auto lis_cur = dp[n-2-(rit-seq.rbegin())];
            auto upp_bkd = upper_bound(lis_bwd.end()-lgth, lis_bwd.end(), lis_cur[i]-x);
            if (i+1+(lis_bwd.end()-upp_bkd) < tmp) break;
            res = max(res, tmp);
        }
    }

    // for (auto s = seq.begin(); s != seq.end(); s++) {
    //     auto low = lower_bound(track_end.begin(), track_end.begin()+lgth, *s);
    //     if (low-track_end.begin() < lgth) track_end[low-track_end.begin()] = *s;
    //     else {
    //         track_end[lgth] = *s;
    //         lgth++;
    //     }
    //     track_max[s-seq.begin()] = track_end[lgth-1];
    //     track_lgth[s-seq.begin()] = lgth;

        // if (s-seq.begin() == 121) {
        //     for (auto& e : track_end) cout << e << " ";
        //     cout << "\n";                
        // }
    // }
    // for (auto& e : track_end) cout << e << " ";
    // cout << "\n";

    // res = lgth;
    // lgth = 0;
    // ll pos = 0, lgth1 = 0, lgth2 = 0, M = 0;
    // vector<ll> to_print(n);
    // for (auto rit = seq.rbegin(); rit != seq.rend(); rit++) {
    //     auto upp = upper_bound(track_rvs.end()-lgth, track_rvs.end(), *rit);
    //     if (track_rvs.end()-upp < lgth) track_rvs[n-1-(track_rvs.end()-upp)] = *rit;
    //     else { track_rvs[n-1-lgth] = *rit; lgth++; }
    //     if (rit == seq.rend()-1) { res = max(res, lgth); break; }
    //     auto upp_bk = upper_bound(track_rvs.end()-lgth, track_rvs.end(), track_max[n-2-(rit-seq.rbegin())]-x);
    //     // res = max(res, track_lgth[n-2-(rit-seq.rbegin())] + (track_rvs.end()-upp_bk));
    //     if (track_lgth[n-2-(rit-seq.rbegin())]+(track_rvs.end()-upp_bk) >= res) {
    //         res = track_lgth[n-2-(rit-seq.rbegin())] + (track_rvs.end()-upp_bk);
    //         pos = n - 2 - (rit-seq.rbegin());
    //         lgth1 = track_lgth[n-2-(rit-seq.rbegin())];
    //         lgth2 =  (track_rvs.end()-upp_bk);
    //         M = track_max[n-2-(rit-seq.rbegin())];
    //         to_print = track_rvs;
    //     }
    //     if (rit-seq.rbegin() == n-20) {
    //         cout << "22: " << track_lgth[n-2-(rit-seq.rbegin())] << " + " << (track_rvs.end()-upp_bk) << " " << lgth << "\n";
    //     }
    // }
    // cout << pos << " " << seq[pos] << " " << lgth1 << "+" << lgth2 << " " << M << "\n";

    // for (auto& e : to_print) cout << e << " ";
    // cout << "\n";
    // ofstream file1("04-0301.in"), file2("04-0302.in");
    // file1 << pos+1 << " 0\n";
    // for (ll i = 0; i <= pos; i++) file1 << seq[i] << " ";
    // file2 << n-pos-1 << " 0\n";
    // for (ll i = pos+1; i < n; i++) file2 << seq[i] << " ";
    // file1.close(); file2.close();
    // ofstream file3("04-0303.in");
    // file3 << n << " 0\n";
    // for (ll i = 0; i <= pos; i++) file3 << seq[i] << " ";
    // for (ll i = pos+1; i < n; i++) file3 << seq[i]+x << " ";

    // file3.close();

    // vector<ll> track_fr(n, 0), track_min(n, 0);
    // lgth = 0; // track min
    // for (auto s = seq.rbegin(); s != seq.rend(); s++) {
    //     auto low = lower_bound(track_fr.end()-lgth, track_fr.end(), *s);
    //     if (track_fr.end()-low < lgth) 
    //         track_fr[(low-track_fr.begin())-1] = *s; 
    //     else {
    //         track_fr[n-1-lgth] = *s;
    //         lgth++;
    //     }
    //     track_min[n-1-(s-seq.rbegin())] = track_fr[n-lgth];
    //     track_lgth[n-1-(s-seq.rbegin())] = lgth;
    // }
    // lgth = 0; // forward
    // for (auto it = seq.begin(); it != seq.end()-1; it++) {
    //     auto low = lower_bound(track_end.begin(), track_end.begin()+lgth, *it);
    //     if (low-track_end.begin() < lgth) track_end[low-track_end.begin()] = *it;
    //     else { track_end[lgth] = *it; lgth++; }

    //     auto low_fr = lower_bound(track_end.begin(), track_end.begin()+lgth, track_min[(it-seq.begin())+1]+x);
    //     res = max(res, track_lgth[(it-seq.begin())+1] + (low_fr-track_end.begin()));
    // }
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, milli> ms_double = t2 - t1;
    // cout << ms_int.count() << "ms\n";
    cout << ms_double.count() << "ms\n";
    cout << n << "\n";
    cout << res << "\n";

    return 0;
}
