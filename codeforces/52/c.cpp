#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

template<typename T, T neutral>
struct node {
    ll lm, rm;
    unique_ptr<node> l_child, r_child;
    T val;
    ll lazy = 0;

    node(ll lm_, ll rm_, vector<T>& v) : lm(lm_), rm(rm_), l_child(nullptr), r_child(nullptr) {
        if (lm == rm) {
            val = v[lm];
        } else {
            ll mid = (lm + rm) / 2;
            l_child = make_unique<node>(lm, mid, v);
            r_child = make_unique<node>(mid+1, rm, v);
            calc();
        }
    }

    void calc() {
        if (lm == rm) return;
        val = comb(l_child->val, r_child->val);
    }

    T comb(T a, T b) {
        return min(a, b);
    }
    
    void range_update(ll l, ll r, T inc) {
        push_lazy();

        if (r < lm || l > rm) return;
        
        if (l <= lm && r >= rm) {
            val += inc;
            if (lm != rm) {
                l_child->lazy += inc;
                r_child->lazy += inc;
            }
            return;
        }

        l_child->range_update(l, r, inc);
        r_child->range_update(l, r, inc);
        calc();
    }

    void push_lazy() {
        if (lazy != neutral) {
            val += lazy;
            if (lm != rm) {
                l_child->lazy += lazy;
                r_child->lazy += lazy;
            }
            lazy = 0;
        }
    }

    ll rq(ll l, ll r) {
        if (l > rm || r < lm) return neutral;
        push_lazy();
        if (l <= lm && r >= rm) return val;
        return comb(l_child->rq(l, r), r_child->rq(l, r));
    }
};


int main(){
    _;
    ll n; cin >> n;
    v64 v(2*n);
    forn(i, 0, n) cin >> v[i], v[i+n] = v[i];

    node<ll, INF> seg(0, 2*n - 1, v);
    ll q; cin >> q;
    string line;
    getline(cin, line);
    forn(i, 0, q) {
        v64 query;
        getline(cin, line);
        istringstream iss(line);
        ll num;
        while(iss >> num) {
            query.push_back(num);
        }

        if (query.size() == 2) {
            if (query[0] <= query[1]) {
                cout << seg.rq(query[0], query[1]) << ln;
            } else {
                cout << seg.rq(query[0], query[1] + n) << ln;
            }
        } else {
            if (query[0] <= query[1]) {
                seg.range_update(query[0], query[1], query[2]);
                seg.range_update(query[0] + n, query[1] + n, query[2]);
            } else {
                seg.range_update(0, query[1], query[2]);
                seg.range_update(query[0], n+query[1], query[2]);
                seg.range_update(query[0]+n, 2*n-1, query[2]);
            }
        }
    }

    return 0;
}