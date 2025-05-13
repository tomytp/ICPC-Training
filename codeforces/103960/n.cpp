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

void move(multiset<ll>& ma, multiset<ll>& mb, ll val) {
    ma.erase(ma.find(val));
    mb.insert(val);
}

int main(){
    _;
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    ll k, l; cin >> k >> l;
    
    v64 wa, wb;
    multiset<ll> escolhidos, nao_escolhidos;
    ll a_sum = 0, b_sum = 0;
    forn(i, 0, k) {
        wa.push_back(a[n-k+i]);
        wb.push_back(b[n-k+i]);
        nao_escolhidos.insert(b[n-k+i]);
        a_sum += a[n-k+i];
    }
    forn(i, 0, k) {
        wa.push_back(a[i]);
        wb.push_back(b[i]);
    }
    forn(i, 0, l) {
        ll v = *(--nao_escolhidos.end());
        b_sum += v;
        move(nao_escolhidos, escolhidos, v);
    }
    ll max_sum = a_sum + b_sum;


    forn(i, 0, wa.size() - k) {
        a_sum -= wa[i];
        a_sum += wa[i+k];

        auto it = nao_escolhidos.find(wb[i]);
        if (it != nao_escolhidos.end()) {
            nao_escolhidos.erase(it);
        } else {
            it = escolhidos.find(wb[i]);
            escolhidos.erase(it);
            b_sum -= wb[i];
        }
        nao_escolhidos.insert(wb[i+k]);

        if (escolhidos.size() < l) {
            ll v = *(--nao_escolhidos.end());
            b_sum += v;
            move(nao_escolhidos, escolhidos, v);
        }

        while (*nao_escolhidos.rbegin() > *escolhidos.begin()) {
            ll va = *nao_escolhidos.rbegin();
            ll vb = *escolhidos.begin();
            b_sum += va - vb;
            move(nao_escolhidos, escolhidos, va);
            move(escolhidos, nao_escolhidos, vb);
        }
        max_sum = max(max_sum, a_sum + b_sum);
        // debug(max_sum);
        // debug(a_sum);
        // debug(b_sum);
        // for(auto x : escolhidos) cout << x << " ";
        // cout << ln;
        // for(auto x : nao_escolhidos) cout << x << " ";
        // cout << ln;
        // cout << "---------------\n";
    }

    cout << max_sum << ln;
    
    return 0;
}