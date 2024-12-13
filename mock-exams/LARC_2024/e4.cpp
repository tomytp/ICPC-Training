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

set<ll> open, closed;
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

void fill_asc() {
    forn(i, 0, n) {
        if (v[i] != 0) continue;
        auto it = open.begin();
        v[i] = *it;
        open.erase(it);
    }
}

void fill_desc() {
    for (ll i = n-1; i >= 0; i--) {
        if (v[i] != 0) continue;
        auto it = open.begin();
        v[i] = *it;
        open.erase(it);
    }
}

bool is_valid() {
    ll peak = 0;
    forn (i, 0, n) {
        if (v[i] == n) {
            peak = i;
            break;
        }
    }
    forn(i, 0, peak) {
        if (v[i] > v[i+1]) return false;
    }
    forn(i, peak, n-1) {
        if (v[i] < v[i+1]) return false;
    }

    return true;
}

void fill(ll guess, ll prefered, ll previous, ll alternate) {
    if (guess > previous) {
        v[prefered] = guess;
    } else {
        v[alternate] = guess;
    }
}


int main(){
    F_;
    cin >> n;
    v.resize(n);
    forn(i, 0, n) {
        cin >> v[i];
        if (v[i] != 0) closed.insert(v[i]);
    }

    forn(i, 1, n+1) {
        if (closed.find(i) == closed.end()) open.insert(i); 
    }

    ll l = 0;
    ll r = n-1;
    
    while (true) { 
        if (v[l] == n) {
            fill_desc();
            break;
        }
        if (v[r] == n) {
            fill_asc();
            break;
        }

        if (v[l] != 0) {
            l++;
            continue;
        }

        if (v[r] != 0) {
            r--;
            continue;
        }

        ll l_bound = find_next(l);
        ll r_bound = find_back(r);

        if (l_bound == n) {
            fill_desc();
            break;
        }
        if (r_bound == -1) {
            fill_asc();
            break;
        }
        
        ll l_minus = l == 0 ? 0 : v[l-1];
        ll r_plus = r == n-1 ? 0 : v[r+1];
        ll guess = *open.begin();
        open.erase(guess);

        if (r_bound < l_bound) {
            if (l_minus > r_plus) {
                fill(guess, l, l_minus, r);
            } else {
                fill(guess, r, r_plus, l);
            }
            continue;
        } else if (l_bound == r_bound) {
            if (abs(r-r_bound) < abs(l-l_bound)) {
                fill(guess, r, r_plus, l);
            } else {
                fill(guess, l, l_minus, r);
            }
            continue;
        }

        if (v[l_bound] < v[r_bound]) {
            fill(guess, l, l_minus, r);
        } else {
            fill(guess, r, r_plus, l);
        }
    }

    if (!is_valid()) {
        cout << "*" << ln;
    } else {
        forn(i, 0, n) {
            cout << v[i] << " \n"[i==n-1];
        }
    }
    
    P_; return 0;
}