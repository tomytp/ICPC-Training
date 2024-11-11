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
    fast_cin();
    string a, b;
    cin >> a >> b;
    map<char, pair<int,int>> mp;
    for(auto c : a) {
        mp[c].first++;
    }
    for(auto c : b) {
        mp[c].second++;
    }

    for(auto e : mp) {
        forn(i, 0, max(e.second.first, e.second.second)) {
            cout << e.first;
        }
    }
    cout << ln;
}