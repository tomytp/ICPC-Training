#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define MAXN 2005
#define P1 17
#define Q1 19
#define P2 23
#define Q2 31
#define MOD1 1'000'000'007
#define MOD2 1'000'000'009

ll r,c,a,b;
vector<vp64> haxx(MAXN, vp64(MAXN,p64(0,0)));
vector<vp64> hac(MAXN, vp64(MAXN,p64(0,0)));
vector<vp64> har(MAXN, vp64(MAXN,p64(0,0)));

ll powp1[MAXN];
ll powq1[MAXN];
ll powp2[MAXN];
ll powq2[MAXN];

p64 sum(p64 p1, p64 p2){
    p64 np = p64(0,0);
    np = p64((p1.first+p2.first)%MOD1, (p1.second+p2.second)%MOD2);
    return np;
}
p64 diff(p64 p1, p64 p2){
    p64 np = p64(0,0);
    np = p64((p1.first-p2.first)%MOD1, (p1.second-p2.second)%MOD2);
    if(np.first < 0){
        np.first = (np.first+ MOD1)%MOD1;
    }
    if(np.second < 0){
        np.second= (np.second+ MOD2)%MOD2;
    }
    return np;
}

void ppair(p64 p){
    cout << p.first << ' ' << p.second << ln;
}

void precomp(){
    powp1[0] = 1;
    powp2[0] = 1;
    powq1[0] = 1;
    powq2[0] = 1;
    forn(i,0,NAME_MAX-1){
        powp1[i+1] = (powp1[i]*P1)%MOD1;
        powq1[i+1] = (powq1[i]*Q1)%MOD1;
        powp2[i+1] = (powp2[i]*P2)%MOD2;
        powq2[i+1] = (powq2[i]*Q2)%MOD2; 
    }
}

p64 querry_r(ll i, ll j){
    p64 out;
    if(j == 0){
        out = har[i][j+b];
    }else{
        out = diff(har[i][j+b],har[i][j-1]);
    }
    //ppair(out);
    return out;
}

p64 querry_c(ll i, ll j){
    p64 out;
    if(i == 0){
        out = har[i+a][j];
    }else{
        out = diff(hac[i+a][j],hac[i-1][j]);
    }
    //ppair(out);
    return out;
}

void acum_sum(){
    forn(i,0,c){
        hac[i][0] = haxx[i][0];
        //ppair(haxx[i][0]);
        forn(j,1,r){
            hac[i][j] = sum(hac[i][j-1], haxx[i][j]);
        }
    }
    forn(j,0,r){
        har[0][j] = haxx[0][j];
        forn(i,1,c){
            har[i][j] = sum(hac[i-1][j], haxx[i][j]);
        }
    }
}

int main() {
    fast_cin();
    precomp();
    ll rk,ck, rh, ch, counter;
    cin >> rk >> ck;
    vector<vector<char>> key(rk,vector<char>(ck));
    forn(i,0,rk){
        forn(j,0,ck){
            cin >> key[i][j];
        }
    }
    cin >> rh >> ch;
    vector<vector<char>> haystack(rh,vector<char>(ch));
    forn(i,0,rh){
        forn(j,0,ch){
            cin >> haystack[i][j];
        }
    }
    r = rh;
    c = ch;
    a = rk;
    b = ck;

    p64 khax = p64(0,0);

    forn(i,0,r){
        forn(j,0,c){
            haxx[i][j].first = ((ll)(haystack[i][j]-'a'+1)* (powp1[i]*powq1[j]%MOD1))%MOD1;
            haxx[i][j].second = ((ll)(haystack[i][j]-'a'+1)* (powp2[i]*powq2[j]%MOD2))%MOD2;
            //ppair(haxx[i][j]);
        }
    }

    forn(i,0,a){
        forn(j,0,b){
            p64 aux = p64(((ll)(key[i][j]-'a'+1)* (powp1[i]*powq1[j]%MOD1))%MOD1, ((ll)(key[i][j]-'a'+1)* (powp2[i]*powq2[j]%MOD2))%MOD2);
            khax = sum(khax, aux); 

        }
    }

    acum_sum();
    p64 phax = p64(0,0);
    forn(i,0,a){
        forn(j,0,b){
            phax = sum(phax, haxx[i][j]);
        }
    }
    p64 qhax = phax;
    forn(i,0,r-a){
        phax = qhax;
        forn(j,0,c-b){
            if(phax == khax){
                dbg(i);dbg(j);
                cout << ln;
            }
            phax = diff(sum(phax, querry_c(i,j+b)), querry_c(i,j));
            ppair(phax);
        }
        
        //ppair(qhax);
        qhax = diff(sum(qhax, querry_r(i+a,0)), querry_r(i,0));
        //ppair(qhax);
    }

}