#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 100100;

int main(){
    _;
    ll n; cin >> n;
    vector<p64> v(n);
    forn(i, 0, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<ll> time(MAXN, -1);
    ll cur = 0;
    ll fila = -1;
    ll last_set = 0;

    forn(i, 0, MAXN) {
        if (time[i] == -1 && fila != -1) {
            forn(j, 0, 10) {
                time[i+j] = fila;
            }
            fila = -1;
        }
        if (cur < n && v[cur].first == i) {
            if (time[i] == v[cur].second || time[i] == -1) {
                forn(j, 0, 10) {
                    time[i+j] = v[cur].second;
                }
            } else {
                fila = v[cur].second;
            }
            cur++;
        }
        if (time[i] != -1) last_set = i;
    }

    // forn(i, 0, last_set + 3) cout << time[i] << " \n"[i==last_set+2];
    cout << last_set+1 << ln;

    return 0;
}