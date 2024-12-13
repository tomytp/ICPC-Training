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

set<ll> closed;
ll n;
v64 v;

ll find_next(ll i) {
    forn(j, i, n) {
        if (v[j] != 0) return j;
    }
    return n;
}

ll find_back(ll i) {
    for (ll j = i; j >= 0; j--) {
        if (v[j] != 0) return j;
    }
    return -1;
}

bool solve() {
    cin >> n;
    v.resize(n);
    forn(i, 0, n) {
        cin >> v[i];
        if (v[i] != 0) closed.insert(v[i]);
    }

    ll l = 0;
    ll r = n-1;
    ll curr = 1;
    while (l <= r) {
        if (v[l] == curr) {
            l++; curr++; continue;
        }
        if (v[r] == curr) {
            r--; curr++; continue;
        }

        if (closed.find(curr) != closed.end()) return false;
        if (closed.find(curr) == closed.end() && v[l] && v[r]) return false;

        if (!v[l] && v[r]) {
            v[l] = curr; l++; curr++; continue;
        }
        if (v[l] && !v[r]) {
            v[r] = curr; r--; curr++; continue;
        }

        ll l_bound = find_next(l);
        ll r_bound = find_back(r);

        if (l_bound == r_bound) {
            if (abs(l - l_bound) < abs(r - r_bound)) {
                v[l] = curr; l++; curr++; continue;
            } else {
                v[r] = curr; r--; curr++; continue;
            }
        } else if (l_bound > r_bound) {
            v[r] = curr;  r--; curr++; continue;
        } else {
            if (v[l_bound] < v[r_bound]) {
                v[l] = curr; l++; curr++; continue;
            } else {
                v[r] = curr; r--; curr++; continue;
            }
        }
    }
    return true; 
}

int main(){
    F_;
    
    if (!solve()) {
        cout << "*" << ln;
    } else {
        forn(i, 0, n) {
            cout << v[i] << " \n"[i==n-1];
        }
    }
    
    P_; return 0;
}