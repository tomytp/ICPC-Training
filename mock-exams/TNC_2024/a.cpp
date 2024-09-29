#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(i = s; i < e; i++)
#define mp make_pair

int main() {
    FAST_CIN;
    ll n; cin >> n;
    ll resp = 0;
    for(ll i = n; i > 2; i -= 2){
        resp += 1 + ((i-2)*(i-1))/2;
    }
}
