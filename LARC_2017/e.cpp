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
    fast_cin();
    ll n, l, f=0, counter=0, aux, pow=1, aux2=0;
    string s;
    cin >> s >> n;
    l = sz(s);
    v64 v(5,0), num(l), index(5,-1);
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
            f = (f+(ll)(s[i]-'0')*pow)%n;
            num[i]=s[i] -'0';
        }
        pow = (pow*10)%n;
    }

    forn(a,10){
        if(aux && a==0 && counter == 5) continue;
        forn(b,10){
            if(aux && b==0 && counter == 4) continue;
            forn(c,10){
                if(aux && c==0 && counter == 3) continue;
                forn(d,10){
                    if(aux && d==0 && counter == 2) continue;
                    forn(e,10){
                        if(aux && e==0 && counter == 1) continue;
                        if((v[4]*a+v[3]*b+v[2]*c+v[1]*d+v[0]*e+f)%n==0){
                            if(index[4]!=-1) num[index[4]]=a;
                            if(index[3]!=-1) num[index[3]]=b;
                            if(index[2]!=-1) num[index[2]]=c;
                            if(index[1]!=-1) num[index[1]]=d;
                            if(index[0]!=-1) num[index[0]]=e;
                            forn(i,l){
                                cout << num[i];
                            }
                            cout << ln ;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << '*' << ln;
}