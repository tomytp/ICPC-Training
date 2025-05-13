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

struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;

    static constexpr ll neutral = ll(); // e.g., 0 for sum, INF for min, etc.
    ll val = neutral;
    ll lazy_add = ll();
    optional<ll> lazy_set = nullopt;

    node(ll lm_, ll rm_, const vector<ll>& v) : lm(lm_), rm(rm_) {
        if (lm == rm) val = v[lm];
        else {
            ll mid = (lm + rm) / 2;
            lc = make_unique<node>(lm, mid, v);
            rc = make_unique<node>(mid + 1, rm, v);
            pull();
        }
    }

    void push() {
        if (lazy_set.has_value()) {
            val = *lazy_set * (rm - lm + 1);
            if (lm != rm) {
                lc->lazy_set = rc->lazy_set = lazy_set;
                lc->lazy_add = rc->lazy_add = ll();
            }
            lazy_set.reset();
        }
        if (lazy_add != ll()) {
            val += lazy_add * (rm - lm + 1);
            if (lm != rm) {
                if (lc->lazy_set) *lc->lazy_set += lazy_add;
                else lc->lazy_add += lazy_add;

                if (rc->lazy_set) *rc->lazy_set += lazy_add;
                else rc->lazy_add += lazy_add;
            }
            lazy_add = ll();
        }
    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    static ll comb(ll a, ll b) {
        return a + b;
    }

    void range_add(ll lq, ll rq, ll x) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lazy_add += x;
            push();
            return;
        }
        lc->range_add(lq, rq, x);
        rc->range_add(lq, rq, x);
        pull();
    }

    void range_set(ll lq, ll rq, ll x) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lazy_set = x;
            lazy_add = ll();
            push();
            return;
        }
        lc->range_set(lq, rq, x);
        rc->range_set(lq, rq, x);
        pull();
    }

    ll query(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }

    void point_set(ll idx, ll x) {
        push();
        if (lm == rm) {
            val = x;
            return;
        }
        if (idx <= lc->rm) lc->point_set(idx, x);
        else rc->point_set(idx, x);
        pull();
    }
};

void solve_partity(v64& v) {
    ll n = v.size();
    v64 idx(n);
    forn(i, 0, n) {
        idx[v[i]] = i;
    }
    node seg(0, n-1, idx);
    
}

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 odds, evens;
    forn(i, 0, n) {
        if ((i+1) & 1) {
            odds.push_back(v[i]);
        } else {
            evens.push_back(v[i]);
        }
    }
    



    // forn(i, 0, n) cout << ans[i] << " \n"[i==n - 1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}