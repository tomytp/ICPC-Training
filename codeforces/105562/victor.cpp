#include <bits/stdc++.h>
using namespace std;

int classificador(vector<int>& s, int q){
    int count;
    int res;
    
    count= s.size();

    if(count == 0){
        return -1;
    }

    for(int i =0; i<count;i++){
        if(s[i]>=q){
            res= s[i];
            s.erase(s.begin() + i);
            return res;
        }
    }
    return -1;
}

int main(void){
    int n,q;
    int use;
    int res;

    
    cin>> n>>q;
    vector<int> v;
    
    for(int i =0;i<n;i++){
        cin >> use;
        v.push_back(use); 
    }

    sort(v.begin(),v.end());
    
    for(int i =0;i<q;i++){
        cin >> use;
        res= classificador(v,use);
        cout << res<<"\n";
    }
    return 0;
}