#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
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

#define MAXT 20000005

int main() {
    fast_cin();
    ll n; cin >> n;
    vector<pp64> vec(n + 1);
    queue<pp64> fila;
    set<ll> tristes;
    vec[0].fi.fi = -1000;
    forn(i, 1, n+1) {
        cin >> vec[i].fi.fi >> vec[i].fi.se >> vec[i].se.fi;
        vec[i].se.se = i;
    }
    sort(vec.begin(), vec.end());

    ll currentSong = -1, finishTime = -1, idx = 1;
    forn(t, 1, MAXT) {
        if (t == finishTime) {
            currentSong = -1;
        }
        if (vec[idx].fi.fi == t) {
            if (vec[idx].se.fi) {
                tristes.insert(currentSong);
                currentSong = vec[idx].se.se;
                finishTime = vec[idx].fi.se + t;
            } else {
                fila.push(vec[idx]);
            }
            idx++;
        }
        if (currentSong == -1 && (ll) fila.size()) {
            pp64 curr = fila.front();
            fila.pop();
            currentSong = curr.se.se;
            finishTime = curr.fi.se + t;
        }
    }

    tristes.erase(-1);
    cout << tristes.size() << ln;
    for(auto v : tristes) {
        cout << v << " ";
    }
    cout << ln;
}