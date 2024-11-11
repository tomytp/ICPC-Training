#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


int main() {
    // fast_cin();
    ll n, colors, spacing; cin >> n >> colors >> spacing;
    ll m; cin >> m;
    v64 vec(n);
    set<p64> validos;
    set<p64> invalidos;
    map<ll, ll> counter;

    forn(i,0,m) {
        cin >> vec[i];
        counter[vec[i]]++;
    }

    ll start = 0;
    if (spacing < m) {
        start = m - spacing;
    }

    unordered_set<ll> s;
    forn(i, start, m) {
        s.insert(vec[i]);
        invalidos.emplace(i, vec[i]);
    }
    forn(i, 1, colors+1) {
        if (s.find(i) == s.end()) {
            validos.emplace(counter[i], i);
        }
    }
    forn(i, m, n) {
        while(invalidos.size() > 0 && i - invalidos.begin()->first > spacing) {
            validos.emplace(counter[invalidos.begin()->second], invalidos.begin()->second);
            invalidos.erase(invalidos.begin());
        }
        if (validos.size() == 0) {
            cout << "impossible" << ln;
            return 0;
        }

        vec[i] = validos.begin()->second;
        counter[vec[i]]++;
        invalidos.emplace(i, validos.begin()->second);
        validos.erase(validos.begin());
    }

    set<ll> coj;
    forn(i,0,min(spacing,n)){
        if(coj.find(vec[i]) == coj.end()){
            coj.insert(vec[i]);
        }else{
            cout << "impossible" << ln;
            return 0;
        }
    }
    forn(i,min(spacing,n),n){
        coj.erase(vec[i-spacing]);
        if(coj.find(vec[i]) == coj.end()){
            coj.insert(vec[i]);
        }else{
            cout << "impossible" << ln;
            return 0;
        }
    }

    forn(i, 0, n) {
        cout << vec[i] << " ";
    }
    cout << ln;
}