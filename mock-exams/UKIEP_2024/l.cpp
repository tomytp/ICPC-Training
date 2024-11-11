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
    string arm = "\xF0\x9F\x92\xAA";
    string rest = "\xF0\x9F\x98\x8E";
    string leg = "\xF0\x9F\xA6\xB5";
    
    vector<string> v;
    ll n;
    cin >> n;
    forn(i, 0, n) {
        string aux; cin >> aux;
        if (aux.find("rest") != aux.npos) {
            v.push_back(rest);
        } else if (aux.find("leg") != aux.npos) {
            v.push_back(leg);
        } else {
            v.push_back(arm);
        }
    }

    forn(i, 0, 5) {
        cout << i+1 << " ";
        forn(j, 0, 7) {
            if (i*7 + j >= 31) continue;
            cout << v[(i*7 + j) % n];
        }
        cout << ln;
    }
}