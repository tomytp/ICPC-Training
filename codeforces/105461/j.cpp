#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll ALF = 26;

int main(){
    ll n; cin >> n;
    v64 vec(n);
    v64 resp(n,1);

    vector<string> s(4, string(n, 'a'));

    forn(i,0,n){
        ll aux = i;
        forn(j,0,4){
            s[j][i] += aux%ALF; 
            aux = aux/ALF;
        }

    }

    ll pot_alf = 1;

    forn(h, 0, 4){
        cout << "? " << s[h] << ln;
        cout.flush();
        string inp;
        cin >> inp;

        forn(i,0,n){
            resp[i] += (inp[i]-'a')*pot_alf;
        }
        pot_alf *= ALF;
    }

    v64 resp2(n);

    forn(i,0,n){
        resp2[resp[i]-1] = i+1;
    }

    swap(resp, resp2);

        
    cout << "! ";
    forn(i,0,n) cout << resp[i] << " \n"[i==n-1];

    return 0;
}