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

struct block {
    set<ll> zero, one, two;
};

void solve() {
    ll n; cin >> n;
    v64 v(n);
    v64 size(3, 0);
    block a, b, c;
    forn(i, 0, n) {
        cin >> v[i];
        size[v[i]]++;
    }

    forn(i, 0, size[0]) {
        if (v[i] == 0) {
            a.zero.insert(i);
        } else if (v[i] == 1) {
            a.one.insert(i);
        } else {
            a.two.insert(i);
        }
    }
    forn(i, size[0], (size[0] + size[1])) {
        if (v[i] == 0) {
            b.zero.insert(i);
        } else if (v[i] == 1) {
            b.one.insert(i);
        } else {
            b.two.insert(i);
        }
    }
    forn(i, (size[0] + size[1]), n) {
        if (v[i] == 0) {
            c.zero.insert(i);
        } else if (v[i] == 1) {
            c.one.insert(i);
        } else {
            c.two.insert(i);
        }
    }

    vp64 swapList;

    if (b.one.size() == size[1] && a.zero.size() != size[0]) {
        swapList.emplace_back(*b.one.begin(), *a.two.begin());
        b.two.insert(*b.one.begin());
        a.one.insert(*a.two.begin());

        a.two.erase(a.two.begin());
        b.one.erase(b.one.begin());
    }

    if (b.one.size() == size[1] && c.two.size() != size[2]) {
        swapList.emplace_back(*b.one.begin(), *c.zero.begin());
        c.one.insert(*c.zero.begin());
        b.zero.insert(*b.one.begin());

        c.zero.erase(c.zero.begin());
        b.one.erase(b.one.begin());
    }

    ll swaps = 0;
    do {
        swaps = 0;
        if (!a.one.empty() && !c.zero.empty()) {
            swapList.emplace_back(*a.one.begin(), *c.zero.begin());
            a.zero.insert(*a.one.begin());
            c.one.insert(*c.zero.begin());

            c.zero.erase(c.zero.begin());
            a.one.erase(a.one.begin());
            swaps++;
        }
        if (!c.one.empty() && !a.two.empty()) {
            swapList.emplace_back(*c.one.begin(), *a.two.begin());
            a.one.insert(*a.two.begin());
            c.two.insert(*c.one.begin());

            c.one.erase(c.one.begin());
            a.two.erase(a.two.begin());
            swaps++;
        }
    } while (swaps);

    dbg(a.one.size());
    while (!a.one.empty()) {
        swapList.emplace_back(*a.one.begin(), *b.zero.begin());
        a.zero.insert(*a.one.begin());
        b.one.insert(*b.zero.begin());

        b.zero.erase(b.zero.begin());
        a.one.erase(a.one.begin());
    }
    
    while (!c.one.empty()) {
        swapList.emplace_back(*c.one.begin(), *b.two.begin());
        c.two.insert(*c.one.begin());
        b.one.insert(*b.two.begin());

        b.two.erase(b.two.begin());
        c.one.erase(c.one.begin());
    }
    cout << swapList.size() << ln;
    forn(i, 0, swapList.size()) {
        if (swapList[i].first > swapList[i].second) swap(swapList[i].first, swapList[i].second);
        cout << swapList[i].first + 1 << " " << swapList[i].second + 1 << ln;
    }
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}