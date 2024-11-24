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

void solve() {
    ll n; cin >> n;
    v64 v(n);
    priority_queue<p64> s;
    forn(i, 0 , n) {
        ll aux; cin >> aux;
        if (aux > 0) s.emplace(aux, i+1);
    }
    vp64 resp;
    while (s.size() >= 2) {
        auto a = s.top(); s.pop();
        auto b = s.top(); s.pop();
        a.first--; b.first--;
        resp.emplace_back(a.second, b.second);
        if (a.first > 0) s.push(a);
        if (b.first > 0) s.push(b);
    }

    cout << resp.size() << ln;
    forn (i, 0, resp.size()) {
        cout << resp[i].first << " " << resp[i].second << ln;
    }
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();

    P_; return 0;
}