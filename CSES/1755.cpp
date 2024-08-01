#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define MOD 1000000007L


int main() {
    fast_cin();
    string s; cin >> s;
    map<char, ll> mp;

    for (auto& c : s) {
        mp[c]++;
    }

    ll odd_counter = 0;
    char oddc;
    for (auto& pair : mp) {
        if (pair.second & 1) {
            odd_counter++;
            oddc = pair.first;
        }
    }

    if (odd_counter > 1) {
        cout << "NO SOLUTION" << ln;
        return 0;
    }

    for (auto& pair : mp) {
        if (!(pair.second & 1)) {
            cout << string(pair.second /2, pair.first);
        }
    }

    if (odd_counter == 1) {
        cout << string(mp[oddc], oddc);
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (!(it->second & 1)) {
            cout << string(it->second / 2, it-> first);
        }
    }

    cout << ln;
}
