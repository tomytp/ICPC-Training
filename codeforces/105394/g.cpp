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

vector<string> grid;
map<ll, vector<string>> mp = {
    {3, {
        "VVV",
        "VLL",
        "VPL",
        "PPL",
        "PPL"
    }},
    {4, {
        "VVVT",
        "VTTT",
        "VWWT",
        "PPWW",
        "PPPW"
    }},
    {5, {
        "VVVPP",
        "VWWPP",
        "VFWWP",
        "FFFWL",
        "FLLLL"
    }},
    {6, {
        "VVVNLL",
        "VNLNNL",
        "VNLVNL",
        "NNLVNL",
        "NLLVVV"
    }},
    {7, {
        "VVVTVVV",
        "VTTTLLV",
        "VWWTLPV",
        "PPWWLPP",
        "PPPWLPP"
    }}
};


void preenche(ll x, ll y, vector<string> &mat){
    forn(i, 0, mat.size()){
        forn(j, 0, mat[0].size()){
            grid[x+i][y+j] = mat[i][j];
        }
    }
}

int main(){
    _; ll n, m; cin >> n >> m;
    if(n%5 != 0 and m%5 != 0){
        cout << "no" << ln;
        return 0;
    }
    bool swaped = false;
    if(n%5 != 0){
        swap(n, m);
        swaped = true;
    }
    ll m_orig = m;
    if(m == 1){
        if(n == 5){
            if (swaped) {
                cout << "yes\nIIIII\n";
            } else {
                cout << "yes\nI\nI\nI\nI\nI\n";
            }
            return 0;
        } else {
            cout << "no" << ln;
            return 0;
        }
    }

    grid.resize(n, string(m, '#'));

    if(m == 2){
        if(n == 5){
            cout << "no" << ln;
            return 0;
        }
        vector<string> mat;
        
        mat.push_back("PP");
        mat.push_back("PP");
        forn(i,0,12){
            mat.push_back("NY");
            mat.push_back("YY");
            mat.push_back("NY");
            mat.push_back("NY");
            mat.push_back("NN");
            mat.push_back("YN");
            mat.push_back("YY");
            mat.push_back("YN");
            mat.push_back("YN");
            mat.push_back("NN");
        }
        mat[2][0] = 'P';

        mat[n-1] = "PP";
        mat[n-2] = "PP";
        if(n/5 % 2 == 0){
            mat[n-3] = "PN";
        } else{
            mat[n-3] = "NP";
        }
        grid = mat;
    }
    else{
        forn(i, 0, n/5){
            ll j = 0;
            m = m_orig;
            while(m>7){
                preenche(5*i, 5*j, mp[5]);
                j++;
                m-=5;
            }
            preenche(5*i, 5*j, mp[m]);
        }
    }
    cout << "yes" << ln;
    m = m_orig;
    if(!swaped){
        forn(i, 0, n){
            forn(j, 0, m){
                cout << grid[i][j];
            }
            cout << ln;
        }
    } else {
        forn(j, 0, m){
        forn(i, 0, n){
            cout << grid[i][j];
            }
            cout << ln;
        }
    }
    return 0;
}