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

struct Queries {
    v64 a, b, pref;
    ll n;
    
    ll get_range_sum(ll l, ll r) {
        return pref[r + 1] - pref[l];
    }
    
    ll get_cost(ll l, ll r) {
        if (l == r) return a[l] + 2LL * b[l];
        return get_range_sum(l, r) + b[l] + b[r];
    }
    
    ll solve_query(ll l, ll r) {
        ll result = -1e18;
        forn(i, l, r + 1) {
            forn(j, i, r + 1) {
                forn(k, j + 1, r + 1) {
                    forn(m, k, r + 1) {
                        result = max(result, get_cost(i, j) + get_cost(k, m));
                    }
                }
            }
        }
        return result;
    }

    Queries(ll size) : n(size) {
        a.resize(n);
        b.resize(n);
        pref.resize(n + 1);
    }
    
    void calculate_prefix() {
        pref[0] = 0;
        forn(i, 0, n) pref[i + 1] = pref[i] + a[i];
    }
    
    void read_input() {
        forn(i, 0, n) cin >> a[i];
        forn(i, 0, n) cin >> b[i];
        calculate_prefix();
    }
    
    void handle_query() {
        ll type, p, l, r, x;
        cin >> type;
        
        if (type == 1) {
            cin >> p >> x;
            a[p-1] = x;
            calculate_prefix();
        } else if (type == 2) {
            cin >> p >> x;
            b[p-1] = x;
        } else {
            cin >> l >> r;
            cout << solve_query(l-1, r-1) << ln;
        }
    }
};

int main(){
    F_;
    ll n; cin >> n;
    Queries solver(n);
    solver.read_input();

    ll q; cin >> q;
    while(q--) solver.handle_query();
    
    P_; return 0;
}