#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(i = s; i < e; i++)
#define mp make_pair

void solve3(ll r, ll c){
    cout << "1 " << r+1 << " 1 0 1 1"<< ln;
    cout << "3 " << r << " 0 1 1 "<< c-4 << ln;
    cout << "4 " << r+2 << " 1 2 0 "<< c-5 << ln;
    cout << c << " " << r+1 << " 1 "<< c-5 <<" 1 0"<< ln;
}

void solve4(ll r, ll c){
    cout << "1 " << r+1 << " 1 0 1 "<< c-3 << ln;
    cout << "2 " << r+3 << " 1 1 0 "<< c-3 << ln;
    cout << c-1 << " " << r << " 0 "<< c-3 << " 1 1"<< ln;
    cout << c << " " << r+2 << " 1 "<< c-3 << " 1 0"<< ln;
}

void solve5(ll r, ll c){
    cout << "1 " << r+1 << " 1 0 1 "<< c-3 << ln;
    cout << "2 " << r+3 << " 1 1 0 "<< c-4 << ln;
    cout << c-1 << " " << r << " 0 "<< c-3 << " 1 1"<< ln;
    cout << c << " " << r+2 << " 1 "<< c-3 << " 1 0"<< ln;
    cout << c-1 << " " << r+4 << " 1 "<< c-2 << " 0 1"<< ln;
}

bool solve(ll r, ll c){
    if (c<=2) return false;
    if (r <= 2) return false;
    if (c==3 && r <= 5) return false;
    if (c==4 && r <= 3) return false;
    if (c==5 && r <= 3) return false;

    if(c==3){
        cout << 4 << ln;
        cout << "2 1 0 1 1 1" << ln;
        cout << "3 3 1 1 "<< r-4 << " 0" << ln;
        cout << "1 4 2 0 "<< r-5 << " 1" << ln;
        cout << "2 "<<r<< " " << r-5 << " 1 0 1" << ln;
        return true;
    } 
    
    if(c==4){
        cout << 4 << ln;
        cout << "3 1 0 1 "<< r-3 << " 1" << ln;
        cout << "1 2 1 0 "<< r-3 << " 1" << ln;
        cout << "2 "<<r<< " " << r-3 << " 1 0 1" << ln;
        cout << "4 "<<r-1<< " " << r-3 << " 1 1 0" << ln;
        return true;
    }
    
    if (c==5){
        if(r==4){
            cout << 4 << ln;
            cout << "1 2 1 0 1 2" << ln;
            cout << "2 4 1 1 0 2" << ln;
            cout << "4 1 0 2 1 1" << ln;
            cout << "5 3 1 2 1 0" << ln;
        }
        else {
            cout << 5 << ln;
            cout << "1 "<<r-1<< " " << r-2 << " 0 1 1" << ln;
            cout << "2 2 1 0 "<< r-4 << " 1" << ln;
            cout << "3 "<<r<< " " << r-3 << " 1 0 1" << ln;
            cout << "4 1 0 1 "<< r-3 << " 1" << ln;
            cout << "5 "<<r-1<< " " << r-3 << " 1 1 0" << ln;
        }
        return true;
    } 

    ll currentrow=1;
    if(r%3==1){
        cout << ((r- r%3)/3)*4 << ln;
        solve4(currentrow,c);
        currentrow = 5;
        r-=4;
    } else if(r%3==2){
        cout << ((r- r%3)/3)*4+1 << ln;
        solve5(currentrow,c);
        currentrow=6;
        r-=5;
    } else {
        cout << ((r- r%3)/3)*4 << ln;     
    }

    while(r>0){
        solve3(currentrow,c);
        currentrow+=3;
        r-=3;
    }
    return true;
}

int main() {
    FAST_CIN;
    ll n, r, c, i;
    cin >> n;
    forn(i, 0, n){
        cin >> r >> c;
        if (!solve(r, c)) {
            cout << -1 << ln;
        }
    }
}
