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


int main() {
    fast_cin();
    ll n; cin >> n;
    vector<pp64> vec(n);
    queue<pp64> fila;
    set<ll> tristes;
    forn(i, 0, n) {
        cin >> vec[i].fi.fi >> vec[i].fi.se >> vec[i].se.fi;
        vec[i].se.se = i;
    }
    sort(vec.begin(), vec.end());

    ll currentSong = -1, finishTime = 0;
    for (auto action : vec) {
        while (action.fi.fi >= finishTime && fila.size()) {
            auto ac = fila.front(); fila.pop();
            finishTime = finishTime + ac.fi.se;
            currentSong = ac.se.se;
        }
        if (action.fi.fi >= finishTime) {
            currentSong = -1;
        }

        if (currentSong == -1) {
            finishTime = action.fi.se + action.fi.fi;
            currentSong = action.se.se;
        } else {
            if (action.se.fi) {
                tristes.insert(currentSong);
                finishTime = action.fi.se + action.fi.fi;
                currentSong = action.se.se;
            } else {
                fila.push(action);
            }
        }
    }

    cout << tristes.size() << ln;
    for(auto v : tristes) {
        cout << v + 1 << " ";
    }
    cout << ln;
}