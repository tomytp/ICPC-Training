#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(){
    ll a1,a2,a3;
    ll b1,b2,b3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;

    b1 = b1 - a1;
    b2 = b2 - a2;
    b3 = b3 - a3;

    if(b1 < 0){
        b1 = 0;
    }

    if(b2 < 0){
        b2 = 0;
    }

    if(b3 < 0){
        b3 = 0;
    }

    cout << b1 + b2 + b3 << ln;
}