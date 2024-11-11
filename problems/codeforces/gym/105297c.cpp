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

#define LC nd*2+1
#define RC nd*2+2

struct Node {
    ll pre, sum;
    Node(ll p = 0, ll s = 0) : pre(p), sum(s) {}
    inline Node operator + (const Node& p) const {
        return {min(pre, sum + p.pre), sum + p.sum};
    }
};

const Node NEUTRAL = {1'000'000'000'000, 0LL};

struct SegTree {
    vector<Node> tree;
    ll n;
    Node op(const Node& a, const Node& b) {
        return a + b;
    }
    void _build(const vector<Node>& v, ll nd, ll st, ll ed) {
        if (st == ed){
            tree[nd] = v[st];
        } else {
            ll mid = (st + ed) / 2;
            _build(v, LC, st, mid);
            _build(v, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }
    void _update(ll idx, const Node& val, ll nd, ll st, ll ed) {
        if (st == ed) tree[nd] = val;
        else {
            ll mid = (st + ed) / 2;
            if (idx <= mid) _update(idx, val, LC, st, mid);
            else _update(idx, val, RC, mid + 1, ed);
            tree[nd] = op(tree[LC], tree[RC]);
        }
    }
    Node _query(ll l, ll r, ll nd, ll st, ll ed) {
        if (r < st || ed < l) return NEUTRAL;
        if (l <= st && ed <= r) return tree[nd];
        ll mid = (st + ed) / 2;
        Node left = _query(l, r, LC, st, mid);
        Node right = _query(l, r, RC, mid+1, ed);
        return op(left, right);
    }
    SegTree(const vector<Node>& v) : n(v.size()) {
        tree.resize(4 * n);
        _build(v, 0, 0, n-1);
    }
    void update(ll idx, const Node& val) {
        _update(idx, val, 0, 0, n-1);
    }
    
    Node query(ll l, ll r) {
        return _query(l, r, 0, 0, n-1);
    }
};

ll query(SegTree& seg, ll start, ll n) {
    if (seg.query(start, start+n).pre >= 0) {
        return -1;
    }
    ll l = start, r = start+n-1;
    while (l != r) {
        ll mid = l + (r - l) / 2;
        if (seg.query(start, mid).pre < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return (l % n) + 1;
}

int main(){
    F_;
    ll n, q; cin >> n >> q;
    v64 b(n), c(n);

    forn(i, 0, n) {
        cin >> b[i];
    }
    forn(i, 0, n) {
        cin >> c[i];
    }
    vector<Node> v(n*2);

    forn(i, 0, n*2) {
        ll mod = i%n;
        v[i] = {b[mod] - c[mod], b[mod] - c[mod]};
    }

    SegTree seg(v);

    forn(i, 0, q) {
        ll t, idx; cin >> t >> idx;
        idx--;
        if (t == 1) {
            cout << query(seg, idx, n) << ln;
        } else {
            ll val; cin >> val;
            if (t == 2) {
                b[idx] = val;
            } else {
                c[idx] = val;
            }
            Node aux = Node(b[idx]-c[idx], b[idx]-c[idx]);
            seg.update(idx, aux);
            seg.update(idx+n, aux);
        }
    }

    P_; return 0;
}
