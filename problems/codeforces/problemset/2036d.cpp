#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg
#define N 1001

vector<vector<char>> v(N, vector<char>(N));
ll n, m;

bool check(ll curr_size, char val) {
    if (curr_size == 0 && val == '1') return true;
    if (curr_size == 1 && val == '5') return true;
    if (curr_size == 2 && val == '4') return true;
    if (curr_size == 3 && val == '3') return true;
    return false;
}

ll solve_layer(ll layer) {
    ll curr_size = 0;
    set<p64> tot;

    for (ll i = layer; i < m-layer; i++) {
        if (check(curr_size, v[layer][i])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(layer, i);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[layer][i])) curr_size++;
        }
    }

    for (ll i = layer + 1; i < n-layer-1; i++) {
        if (check(curr_size, v[i][m-layer-1])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(i, m-layer-1);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[i][m-layer-1])) curr_size++;
        }
    }

    for (ll i = m-layer-1; i >= layer ; i--) {
        if (check(curr_size, v[n-layer-1][i])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(n-layer-1, i);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[n-layer-1][i])) curr_size++;
        }
    }

    for (ll i = n-layer-2; i > layer; i--) {
        if (check(curr_size, v[i][layer])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(i,layer);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[i][layer])) curr_size++;
        }
    }

    for (ll i = layer; i < m-layer; i++) {
        if (check(curr_size, v[layer][i])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(layer, i);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[layer][i])) curr_size++;
        }
    }

    for (ll i = layer + 1; i < n-layer-1; i++) {
        if (check(curr_size, v[i][m-layer-1])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(i, m-layer-1);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[i][m-layer-1])) curr_size++;
        }
    }

    for (ll i = m-layer-1; i >= layer ; i--) {
        if (check(curr_size, v[n-layer-1][i])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(n-layer-1, i);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[n-layer-1][i])) curr_size++;
        }
    }

    for (ll i = n-layer-2; i > layer; i--) {
        if (check(curr_size, v[i][layer])) {
            if (curr_size == 3) {
                curr_size = 0;
                tot.emplace(i,layer);
            } else {
                curr_size++;
            }
        } else {
            curr_size = 0;
            if(check(curr_size, v[i][layer])) curr_size++;
        }
    }

    return tot.size();
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) {
        forn (j, 0, m) {
            cin >> v[i][j];
        }
    }

    ll sum = 0;
    forn (i, 0, min(n,m) / 2) {
        sum += solve_layer(i);
    }
    cout << sum << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}