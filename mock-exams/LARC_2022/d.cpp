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

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    char a,b;
    forn(i,n){
        cin >> a >> b;
        if(a == 'Y'){
            cout << 'Y' << ' ';
            h--;
            w++;
        } else if(w == 0){  
            cout << 'Y' << ' ';
            h--;
            w++;
        } else{
            cout << 'N' << ' ';
        }


        if(b == 'Y'){
            cout << 'Y' << ln;
            w--;
            h++;
        } else if(h == 0){
            cout << 'Y' << ln;
            w--;
            h++;
        } else{     
            cout << 'N' << ln;
        }
    }

}