#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

// Hello World
int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    cin.get();
    
    for (ll i = 0; i < t; i++) {
        string name;
        getline(cin, name);
        cout << "Hello " << name << "!\n";
    }

    return 0;
}