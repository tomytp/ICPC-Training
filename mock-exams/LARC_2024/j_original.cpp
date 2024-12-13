#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define P_ if(D_)cout<<"DEBUG\n"
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define dbg(x) if(D_) cout << #x << " = " << "\n";
const double PI = 2* acos(0.0);
#define ln '\n'
#define dgb dbg

double f(double h, ll theta){
    double rad = (PI*theta)/180;
    double resp = h/tan(rad);
    return resp;
}

int main() {
    F_;

    ll teta, n; cin >> teta >> n;
    vector<pair<ll, double>> v(n);
    forn(i, 0, n) {
        ll x, h; cin >> x >> h;
        double dist = f(h, teta);
        v[i] = make_pair(x, dist);
    }
    sort(v.begin(), v.end());
    double curr_end = 0;
    double soma = 0;
    forn(i, 0, n) {
        if (v[i].first + v[i].second < curr_end) continue;
        if (curr_end < v[i].first) soma += v[i].second;
        else soma += (v[i].first + v[i].second) - curr_end;
        curr_end = v[i].first + v[i].second;
    }

    cout << setprecision(20) << soma << ln;

    P_;return 0;
}