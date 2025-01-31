#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln

#define LC 2*nd+1
#define RC 2*nd+2
#define REC ll nd = 0, ll L = 0,  ll R = -1

struct SegTree {
    v64 tree;
    ll n;

    ll op(ll a, ll b) {
        return max(a, b);
    }

    void _build(v64& v, ll nd, ll st, ll ed) {
        if (st == ed){
            tree[nd] = v[st];
        } else {
            ll mid = (st + ed) / 2;
            _build(v, LC, st, mid);
            _build(v, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }

    void _update(ll idx, ll val, ll nd, ll st, ll ed) {
        if (st == ed) tree[nd] = val;
        else {
            ll mid = (st + ed) / 2;
            if (idx <= mid) _update(idx, val, LC, st, mid);
            else _update(idx, val, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }

    ll _query(ll l, ll r, ll nd, ll st, ll ed) {
        if (r < st || ed < l) return 0;
        if (l <= st && ed <= r) return tree[nd];
        ll mid = (st + ed) / 2;
        ll left = _query(l, r, LC, st, mid);
        ll right = _query(l, r, RC, mid+1, ed);
        return op(left, right);
    }

    SegTree(v64& v) : n(sz(v)) {
        tree.resize(4 * n);
        _build(v, 0, 0, n-1);
    }

    void update(ll idx, ll val) {
        _update(idx, val, 0, 0, n-1);
    }

    ll query(ll l, ll r) {
        return _query(l, r, 0, 0, n-1);
    }
};


int main() {
    FAST_CIN;
    ll n, q; cin >> n >> q;
    v64 vec(n);
    forn(i, 0, n) cin >> vec[i];

    SegTree tree(vec);
    forn(i, 0, q) {
        ll group; cin >> group;
        ll start = 0, end = n-1;
        while(start < end) {
            ll mid = (start + end) / 2;
            if (tree.query(start, mid) >= group) {
                end = mid;
                continue;
            } else if (tree.query(mid+1, end) >= group) {
                start = mid + 1;
                continue;
            } else {
                end = -1;
                break;
            }
        }
        if (end == 0) {
            if (tree.query(end, end) >= group) {
                cout << end + 1 << " ";
                if (end != -1) {
                    tree.update(end, tree.query(end,end) - group);
                }
            } else {
                cout << 0 << ln;
            }

        } else {
            cout << end + 1 << " ";
            if (end != -1) {
                tree.update(end, tree.query(end,end) - group);
            }
        }
    }
    cout << ln;
}