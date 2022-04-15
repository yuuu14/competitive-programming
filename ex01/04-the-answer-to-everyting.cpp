#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> nums(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    for (ll i = 0, target, l, r; i < n-2; i++) {
        target = 42 - nums[i];
        l = i+1;
        r = n-1;
        while (l < r) {
            if (nums[l]+nums[r] == target) {
                printf("%lld %lld %lld\n", nums[i], nums[l], nums[r]);
                return 0;
            }
            else if (nums[l]+nums[r] < target)
                l++;
            else r--;
        }
    }
    printf("impossible\n");
    
    return 0;
}

/*
21 15 10 11
first sort
10 11 15 21 25
10 -> 32 -> 11+25 = 36 rightmost to left -> 11+21 = 32 find

1 2 3 4 5
1 -> 41 -> 2+5 -> 3+5 -> 4+5
*/