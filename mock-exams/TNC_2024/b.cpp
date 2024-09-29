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

map<pair<int,int>,char> teclas;

void translate (ll a, ll counter){
    if(a == 7 || a==9){
        if(counter%4!=0){
            cout << teclas[mp(a, counter%4)];
            counter-=counter%4;
        }
        while(counter>0){
            cout << teclas[mp(a,0)];
            counter-=4;
        }
    } else {
        if(counter%3!=0){
            cout << teclas[mp(a, counter%3)];
            counter-=counter%3;
        }
        while(counter>0){
            cout << teclas[mp(a,0)];
            counter-=3;
        }
    }
}

int main() {
    FAST_CIN;

    teclas[mp(2,1)] = 'a';
    teclas[mp(2,2)] = 'b';
    teclas[mp(2,0)] = 'c';
    teclas[mp(3,1)] = 'd';
    teclas[mp(3,2)] = 'e';
    teclas[mp(3,0)] = 'f';
    teclas[mp(4,1)] = 'g';
    teclas[mp(4,2)] = 'h';
    teclas[mp(4,0)] = 'i';
    teclas[mp(5,1)] = 'j';
    teclas[mp(5,2)] = 'k';
    teclas[mp(5,0)] = 'l';
    teclas[mp(6,1)] = 'm';
    teclas[mp(6,2)] = 'n';
    teclas[mp(6,0)] = 'o';
    teclas[mp(7,1)] = 'p';
    teclas[mp(7,2)] = 'q';
    teclas[mp(7,3)] = 'r';
    teclas[mp(7,0)] = 's';
    teclas[mp(8,1)] = 't';
    teclas[mp(8,2)] = 'u';
    teclas[mp(8,0)] = 'v';
    teclas[mp(9,1)] = 'w';
    teclas[mp(9,2)] = 'x';
    teclas[mp(9,3)] = 'y';
    teclas[mp(9,0)] = 'z';

    string s;
    cin >> s;
    ll a=-1, counter = 0, i;
    forn(i, 0, size(s)){
        if(a==-1){
            a=s[i]-'0';
            counter++;
        } else if (a==s[i]-'0'){
            counter ++;
        } else if(a!=s[i]-'0' || i == size(s)-1){
            translate(a, counter);
            a=s[i]-'0';
            counter=1;
        }
    }
    translate(a, counter);
    cout << ln;
}
