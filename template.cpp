#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)

int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;

    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    // do something

    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, milli> ms_double = t2 - t1;
    // cout << ms_int.count() << "ms\n";
    cout << ms_double.count() << "ms\n";

    return 0;
}

// endl flush buffer
// so use '\n' instead

/* STL
vector
push_back(a), pop_back(), size(), [] access
insert(a), erase(a) -> O(n)

set: sorted
insert(a), count(a), erase(a) -> log n

unordered_set: hash-set
multiset: duplicates

pair: compared lexicographically
tuple

priority_queue: sorted lexicographically

<algorithm>
sort(v.begin(), v.end(), [](int a, int b) {
    return a%670 < b%10;
})

next_permutation() -> amortised O(1)
lower_bound() >= , upper_bound() >  for sorted input
nth_element
swap
reverse
unique
shuffle


compiler:
g++ -x c++ -std=gnu++17 -Wall -O2 -static -pip

g++ -Wall -Wextra -fsanitize=undefined, address -D_GLIBCXX_DEBUG -g source.cpp

Weffc++
*/

