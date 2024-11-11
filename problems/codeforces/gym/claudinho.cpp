#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll pre, sum;
    Node(ll p = 0, ll s = 0) : pre(p), sum(s) {}
    Node operator + (const Node& p) const {
        return {min(pre, sum + p.pre), sum + p.sum};
    }
};

struct SegTree {
    vector<Node> tree;
    int n;
    
    SegTree(const vector<ll>& b, const vector<ll>& c) {
        n = b.size();
        tree.resize(4 * (2 * n));
        vector<Node> v(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            int mod = i % n;
            v[i] = Node(b[mod] - c[mod], b[mod] - c[mod]);
        }
        build(v, 1, 0, 2 * n - 1);
    }
    
    void build(const vector<Node>& v, int node, int start, int end) {
        if(start == end) {
            tree[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(v, 2 * node, start, mid);
        build(v, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void update(int idx, ll val, bool isB, const vector<ll>& b, const vector<ll>& c) {
        _update(idx, val, isB, b, c, 1, 0, 2 * n - 1);
        _update(idx + n, val, isB, b, c, 1, 0, 2 * n - 1);
    }
    
    void _update(int idx, ll val, bool isB, const vector<ll>& b, const vector<ll>& c, 
                 int node, int start, int end) {
        if(start == end) {
            int mod = idx % n;
            tree[node] = Node(isB ? val - c[mod] : b[mod] - val, 
                            isB ? val - c[mod] : b[mod] - val);
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid)
            _update(idx, val, isB, b, c, 2 * node, start, mid);
        else
            _update(idx, val, isB, b, c, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    Node query(int l, int r) {
        return _query(l, r, 1, 0, 2 * n - 1);
    }
    
    Node _query(int l, int r, int node, int start, int end) {
        if(r < start || end < l)
            return Node(1e18, 0);
        if(l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return _query(l, r, 2 * node, start, mid) + 
               _query(l, r, 2 * node + 1, mid + 1, end);
    }
    
    int findFirstNegative(int start) {
        if(query(start, start + n - 1).pre >= 0)
            return -1;
            
        int left = start, right = start + n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(query(start, mid).pre < 0)
                right = mid;
            else
                left = mid + 1;
        }
        return (left % n) + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> b(n), c(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    
    SegTree seg(b, c);
    
    while(q--) {
        int t, idx;
        cin >> t >> idx;
        idx--;
        
        if(t == 1) {
            cout << seg.findFirstNegative(idx) << '\n';
        } else {
            ll val;
            cin >> val;
            seg.update(idx, val, t == 2, b, c);
            if(t == 2) b[idx] = val;
            else c[idx] = val;
        }
    }
    
    return 0;
}