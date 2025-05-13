#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin >> n;

    ll sum = 0;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        sum += aux;
    }

    if (sum > 0) {
        cout << ":)" << ln;
    } else if (sum < 0) {
        cout << ":(" << ln;
    } else {
        cout << ":|" << ln;
    }
    return 0;
}