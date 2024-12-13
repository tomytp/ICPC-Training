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

ll n;
string s; 
v64 resp;


ll solve(v64& v) {
    if (v.size() == 1) {
        return 1;
    }
    
    ll best = 0;
    forn(offset, 1, n) {
        map<char, ll> letters;
        for(auto i : v) {
            letters[s[(i + offset) % n]]++;
        }
        ll count = 0;
        for (auto [key, value] : letters) {
            if (value == 1) count++;
        }
        best = max(best, count);
    }
    return best;
}

int main(){
    F_;
    cin >> s;
    n = s.size();
    resp.resize(n, 0);
    map<char, v64> mp; 
    forn(i, 0, n) {
        mp[s[i]].push_back(i);
    }

    ll ans = 0;
    for (auto& [c, v] : mp) {
        ans += solve(v);
    }

    cout << setprecision(8) << (double) ans / n << ln;
    P_; return 0;
}
