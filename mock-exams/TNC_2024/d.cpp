#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;
using vp64 = vector<p64>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define mp make_pair

bool calc_s(p64 p1, p64 p2, ll* s){
    if((p1.first == 0) && (p2.first != 0)) return false;
    if((p1.second == 0) && (p2.second != 0)) return false;

    if((p1.first == 0)&& (p1.second == 0)){
        *s = 0;
        return true;
    }
    if(p1.first == 0){
        if(p2.second%p1.second != 0) return false;
        *s = p2.second/p1.second;
        return true;
    }
    if(p1.second == 0){
        if(p2.first %p1.first != 0) return false;
        *s = p2.first/p1.first;
        return true;
    }

    if((p2.first%p1.first == 0) && (p2.second%p1.second == 0)){
        if(p2.first/p1.first == p2.second/p1.second){
            *s = p2.first/p1.first;
            return true;
        }
    }
    return false;
}
int main() {
    //FAST_CIN;
    ll n; cin >> n;
    ll s, x,y;
    vp64 bac(n,p64(0,0));
    vp64 des(n,p64(0,0));

    forn(i,0,n){
        cin >> des[i].first >> des[i].second;
    }
    forn(i,0,n){
        cin >> bac[i].first >> bac[i].second;
    }

    if(n == 1){
        cout << 1 << ' ' << bac[0].first - des[0].first << ' ' << bac[0].second - des[0].second << ln;
        return 0;
    }

    sort(des.begin(),des.end());
    sort(bac.begin(),bac.end());

    if(bac[0] == bac[n-1]){
        cout << 0 << ' ' << bac[0].first << ' ' << bac[0].second << ln;
        return 0;
    }

    p64 p1 = p64(des[n-1].first - des[0].first, des[n-1].second - des[0].second);
    p64 p2 = p64(bac[n-1].first - bac[0].first, bac[n-1].second - bac[0].second);

    if(!calc_s(p1,p2,&s)){
        cout << -1 << ln;
        return 0;
    }

    p1 = des[0];
    p2 = bac[0];
    p1 = p64(p1.first*s,p1.second*s);
    x = p2.first - p1.first;
    y = p2.second - p1.second;
    forn(i,0,n){
        p1 = des[i];
        p2 = bac[i];
        if(p1.first*s + x != p2.first){
            cout << -1 << ln;
            return 0;
        }
        if(p1.second*s + y != p2.second){
            cout << -1 << ln;
            return 0;
        }
    }
    cout << s << ' ' << x << ' ' << y << ln;
}
