#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<int, int> p32;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v64> vv64;

#define forn(i,s,e) for(ll i = s; i < e; ++i)
#define ln "\n"
#define dbg(x) (cout<<#x<<" = "<<x<<ln)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

ll vec[200001];

int main() {
    // fast_cin();
    ll n; cin >> n;
    ll k; cin >> k;
    vector<queue<ll>> filas(k+1, queue<ll>());
    set<ll> tristes;
    ll curr = 0;
    ll start = 0;
    forn(i, 0, 2*n) {
        ll type; cin >> type;
        if (type == 1) {
            ll p, f; cin >> p >> f;
            vec[curr++] = p;
            filas[f].push(p);
        } else {
            ll f; cin >> f;
            ll p = filas[f].front();
            filas[f].pop();
            if (tristes.find(p) != tristes.end()) {
                continue;
            }
            while (vec[start] != p) {
                tristes.insert(vec[start++]);
            }
            start++;
        }
    }
    cout << sz(tristes) << ln;
    for (auto p : tristes) {
        cout << p << " ";
    }
    cout << ln;
}