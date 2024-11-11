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

#define PRIME 2003

bool checkkey(vector<vector<char>> key, vector<vector<char>> haystack, ll i, ll j, ll rk, ll ck){
    forn(k,0,rk){
        forn(l,0,ck){
            if(haystack[i+(k*PRIME)%rk][j+(l*PRIME)%ck]!=key[(k*PRIME)%rk][(l*PRIME)%ck]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    fast_cin();
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
    vector<vector<bool>> valid(rh,vector<bool>(ch,0));
    forn(i,0,rh-rk+1){
        forn(j,0,ch-ck+1){
            if(checkkey(key, haystack, i, j, rk, ck)){
                forn(k,0,rk){
                    forn(l,0,ck){
                        valid[i+k][j+l]=1;
                    }
                }
            }
        }

    }

    forn(i,0,rh){
        forn(j,0,ch){
            if(valid[i][j]) cout << haystack[i][j];
            else cout << ".";
        }
        cout << ln;
    }

}