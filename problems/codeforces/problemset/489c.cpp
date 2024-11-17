#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

int main(){
    F_;
    ll m, s; cin >> m >> s;

    if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }

    if (s == 0 || m == 0 || s > 9*m || m < (ll) (ceil(s/9.0) + 0.5)) {
        cout << "-1 -1\n";
        return 0;
    }
    string menor(m, '0'), maior(m, '0');
    ll sl = s, sh = s;
    forn(i, 0, m) {
        if (sh >= 9) {
            maior[i] = '9';
            sh -= 9;
        } else {
            maior[i] = '0' + sh;
            break;
        }
    }
    
    forn(i, 0, m) {
        menor[m-1-i] = maior[i];
    }

    if (menor[0] == '0') {
        menor[0] = '1';
        forn(i, 1, m) {
            if (menor[i] != '0') {
                menor[i]--;
                break;
            }
        }
    }


    cout << menor << " " << maior << ln;   

    P_; return 0;
}