#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef pair<ll,ll> p64;
typedef pair<p64,p64> pp64;
typedef pair<pp64, pp64> ppp64; 

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg
#define fi first
#define se second
#define mp make_pair

bool intercircle(p64 pt1, p64 pt2, ll r1, ll r2){

}

bool intersegcircle(pp64 seg, p64 pt, ll r, ppp64* prt_inter){
    vector<pp64> arcos(4);
    pp64 auxinter;
    ll counter=0;
    arcos[0] = mp(mp(pt.fi,pt.se+r),mp(pt.fi+r,pt.se));
    arcos[1] = mp(mp(pt.fi-r,pt.se),mp(pt.fi,pt.se+r));
    arcos[2] = mp(mp(pt.fi-r,pt.se),mp(pt.fi,pt.se-r));
    arcos[3] = mp(mp(pt.fi,pt.se-r),mp(pt.fi+r,pt.se));

    forn(i,0,4){
        if(interseg(seg, arcos[i], &auxinter)){
            if(auxinter.fi == auxinter.se){
                counter++;
                //achou uma intersecao que e um ponto
            } else {
                //achou um segmento
            }
        }
    }

}

bool interseg(pp64 seg1, pp64 seg2, pp64* prt_inter){
    ll slope1 = (ll)(seg1.fi.se-seg1.se.se)/(seg1.fi.fi-seg1.se.fi);
    ll slope2 = (ll)(seg2.fi.se-seg2.se.se)/(seg2.fi.fi-seg2.se.fi);
    ll cte1 = seg1.fi.se-slope1*seg1.fi.fi;
    ll cte2 = seg2.fi.se-slope2*seg2.fi.fi;

    if(slope1 == slope2){
        if(cte1 != cte2) return false;
    
        prt_inter->fi.fi = max(seg1.fi.fi,seg2.fi.fi);
        prt_inter->se.fi = min(seg1.se.fi,seg2.se.fi);
        prt_inter->fi.se = slope1*(prt_inter->fi.fi) + cte1;
        prt_inter->se.se = slope1*(prt_inter->se.fi) + cte2;
        return true;
    }
    if((cte1+cte2)%2==1) return false;
    prt_inter->fi.fi = (ll)(cte1-cte2)/(slope2-slope1);
    prt_inter->se.fi = (ll)(cte1-cte2)/(slope2-slope1);
    prt_inter->fi.se = (ll)(cte1+cte2)/2;
    prt_inter->se.se = (ll)(cte1+cte2)/2;
    return true;
}

int main() {
    FAST_CIN;
    pp64 seg1 = mp(mp(0,0), mp(4,4));
    pp64 seg2 = mp(mp(1,1), mp(5,5));
    pp64 inter = mp(mp(0,1), mp(1,0));
    bool b = interseg(seg1, seg2, &inter);
    cout << b << ln;
    if(b){
        cout << inter.fi.fi << " " << inter.fi.se << ln;
        cout << inter.se.fi << " " << inter.se.se << ln;
    }
}