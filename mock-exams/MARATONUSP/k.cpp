#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<int, int> p32;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v64> vv64;

#define forn(i,s,e) for(ll i = s; i < e; ++i)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

int main() {
    fast_cin();
    ll n; cin >> n;
    n = (ll) (ceil((double )n/3) + 0.5);
    cout << n << ln;
}