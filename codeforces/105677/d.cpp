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
    #define _ 
    #define debug(x) 
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 calc(v64 &vec, ll n){
    stack<p64> s;
    v64 output(n, INF);

    forn(i,0,n){
        while (!s.empty() && s.top().first < vec[i]){
            output[s.top().second] = abs(i-s.top().second);
            s.pop();
        }

        s.push({vec[i],i});
    }
    return output;
}

int main(){ _;
    ll n; cin >> n;
    v64 vec(n);
    ll maior = 0;
    forn(i,0,n){
        cin >> vec[i];
        if(vec[i] > vec[maior]) maior = i;
    }
    v64 dir = calc(vec, n);
    
    reverse(vec.begin(), vec.end());

    v64 esq = calc(vec, n);

    reverse(esq.begin(), esq.end());

    ll resp = 0;
    
    // forn(i,0,n) cout << dir[i] << " \n"[i==n-1];
    // forn(i,0,n) cout << esq[i] << " \n"[i==n-1];

    forn(i,0,n){
        if(min(esq[i], dir[i]) != INF){
            resp += min(esq[i], dir[i]);
        }
    }

    cout << resp << ln;
    return 0;
}