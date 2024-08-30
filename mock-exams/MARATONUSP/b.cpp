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

int main() {
    fast_cin();
    ll n, a, b, counter=0, firstodd=-1, lastodd, dist=0;
    cin >> n;
    v64 maracas(n), distodd(n,0);
    forn(i, 0, n){
        cin >> maracas[i];
    }
    cin >> a >> b;
    a = min(a,b);
    forn(i, 0, n){
        if(maracas[i]%2 == 1){
            counter++;
            if(counter%2==0) dist+=i-lastodd;
            lastodd=i;
        }
    }

    if(counter%2==1) cout << -1;
    else cout << a*min(dist, n-dist);
    cout << ln;
}