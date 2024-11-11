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

vector<double> alpha(16,0);
vector<pair<double,double>> points(34);

pair<double,double> crosspoint(ll i){
    pair<double,double> aux;
    aux.fi = points[2*i].fi + (points[2*i-1])
}

double f(vector<double> alpha){
    
}

vector<double> grad(vector<double> alpha){

}


int main() {
    fast_cin();
    ll n; cin >> n;
    cin >> points[0].fi >> points[0].se;
    forn(i,1,n+1){
        cin >> points[2*i-1].fi >> points[2*i-1].se >> points[2*i].fi >> points[2*i].se;
    }
    cin >> points[2*n+1].fi >> points[2*n+1].se;

    double step;


}