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
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i]; 
    forn(i, 0, n) cin >> b[i];
    ll k; cin >> k;
    map<ll,ll> mp, fin;
    forn(i, 0, k) {
        ll aux; cin >> aux;
        mp[aux]++;
    }

    forn(i, 0, n) {
        if (b[i] > a[i]) {
            cout << "NO\n";
            return;
        }
    }

    stack<ll> st;
    forn(i, 0, n) {
        while (!st.empty() && st.top() < b[i]) st.pop();
        if (b[i] == a[i] || (!st.empty() && st.top() == b[i])) continue;

        if (mp[b[i]] <= 0) {
            cout << "NO\n";
            return;
        }
        mp[b[i]]--;
        st.push(b[i]);
    }
    cout << "YES\n";
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}