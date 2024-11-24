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
    ll hurdles, power_ups, end; cin >> hurdles >> power_ups >> end;
    vp64 hurds(hurdles);
    forn(i, 0, hurdles) cin >> hurds[i].first >> hurds[i].second;
    vp64 powers(power_ups);
    forn(i, 0, power_ups) cin >> powers[i].first >> powers[i].second;

    ll current_power = 1;
    priority_queue<ll> available;
    ll power_idx = 0;
    ll tot = 0;
    for (auto hurdle : hurds) { 
        while(power_idx < power_ups && powers[power_idx].first < hurdle.first) {
            available.push(powers[power_idx].second);
            power_idx++;
        }
        while (current_power <= (hurdle.second - hurdle.first) + 1) {
            if (available.empty()) {
                cout << -1 << ln;
                return;
            }
            current_power += available.top(); available.pop();
            dbg(current_power);
            tot++;
        }
    }
    cout << tot << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}