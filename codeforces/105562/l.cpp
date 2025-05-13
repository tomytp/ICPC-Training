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

ll n, m, x, y;
v64 shelves;
v64 books;
 
bool testa(ll mid){
    debug(mid);
    ll counter_shelves = 0;
    ll counter_books = 0;

    while((counter_shelves < n) && (counter_books < m)){
        if(books[counter_books] > shelves[counter_shelves]){
            debug(counter_books);
            debug(counter_shelves); 
            return false;
        }
        if(counter_shelves < n - mid){
            counter_books += x;
        }else{
            counter_books += y;
        }
        counter_shelves++;
    }

    if(counter_books < m){
        debug(counter_books);
        return false;
    }
    debug(1);
    return true;
}

int main(){
    _;
    cin >> n >> m >> x >> y;
    shelves.resize(n);
    books.resize(m);

    forn(i,0,n) cin >> shelves[i];
    forn(i,0,m) cin >> books[i];

    sort(shelves.rbegin(), shelves.rend());  
    sort(books.rbegin(), books.rend());  

    ll l = 0;
    ll r = n;
    ll ans = -1;
    while (l <= r)
    {
        debug(l);
        debug(r);
        ll mid = (l+r)/2;
        debug(mid);
        if(testa(mid)){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }
    if(ans == -1) cout << "impossible" << ln;
    else cout << ans << ln;
    return 0;
}