#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) ((ll) (x).size())
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L


ll sum[] = {
    0,
    9,
    99,
    999,
    9999,
    99999,
    999999,
    9999999,
    99999999,
    999999999,
    9999999999,
    99999999999,
    999999999999,
    9999999999999,
    99999999999999,
    999999999999999,
    9999999999999999,
    99999999999999999,
    999999999999999999,
    
};
ll powers[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    10000000000000000,
    10000000000000000,
};

int main() {
    fast_cin();
    ll n, k; cin >> n;
    
    while (n--) {
        cin >> k;
        ll lg = floor(log10(k)) + 0.5;
        ll digits = lg + 1; 
    }

    return 0;
}