#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())
#define dbg(x) cout << #x << " = " << x << ln


int main(){
    // fast_cin();
    ll n, l, f, counter=0, aux, pow=1, aux2=0;
    string s;
    cin >> s >> n;
    l = sz(s);
    v64 v(5), num(l), index(5);
    for(ll i=l-1; i>=0;i--){
        if(s[i]=='?' && counter < 5){
            aux = (i==0);
            v[counter]=pow;
            index[counter]=i;
            counter++;
        } else if(s[i]=='?' && counter >= 5){
            num[i]=(i==0);
            if(i==0) f = (f+pow)%n;
        } else {
            f = (f+(s[i]-'0')*pow)%n;
        }
        pow = (pow*10)%n;
    }

    forn(a,10){
        if(aux && a==0) continue;
        forn(b,10){
            forn(c,10){
                forn(d,10){
                    forn(e,10){
                        if((v[4]*a+v[3]*b+v[2]*c+v[1]*d+v[0]*e+f)%n==0){
                            num[index[4]]=a;
                            num[index[3]]=b;
                            num[index[2]]=c;
                            num[index[1]]=d;
                            num[index[0]]=e;
                            forn(i,l) cout << num[i];
                            cout << ln;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << '*\n';
}