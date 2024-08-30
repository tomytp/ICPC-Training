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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

bool is_valid(double r, ll R, ll p1x, ll p1y, ll p2x, ll p2y) {
    double d = sqrt((p1x - p2x) * (p1x - p2x) + (p1y - p2y) * (p1y - p2y));

    double r1 = (p1x*p1x) + (p1y*p1y) + r;
    double r2 = (p2x*p2x) + (p2y*p2y) + r;

    return (r1 + r2 >= d && r <= R);
}


int main() {
    fast_cin();
    ll R; cin >> R;

    ll p1x, p1y, p2x, p2y; cin >> p1x >> p1y >> p2x >> p2y;
    double mini = 0, maxi = R;
    while (abs(mini - maxi) > 0.0000000001) {
        dbg(maxi); dbg(mini);
        double mid = (mini + maxi) / 2;
        if (is_valid(mid, R, p1x, p1y, p2x, p2y)) {
            mini = mid;
        } else {
            maxi = mid;
        }
    }

    cout << mini << " " << maxi << ln;   
}