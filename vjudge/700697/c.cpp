#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    vector<ll> sum;
    vector<ll> max;
    vector<ll> min;
    int op;cin>>op;
    int type;
    ll input;
    ll output;
    cin>>type>>input;
    sum.push_back(input);
    max.push_back(input);
    min.push_back(input);

   

    for(int i = 0;i<op-1;i++){
        cin>>type>>input;
        if(type==1){
            sum.push_back(input + sum.back());
            if(max.back() < input){
                max.push_back(input);
            }
            else{
                max.push_back(max.back());
            }
            if(min.back() > input){
                min.push_back(input);
            }
            else{
                min.push_back(min.back());
            }
        }
        if(type==2){
            output=max[input-1];
            max.push_back(max.back());
            min.push_back(min.back());
            sum.push_back(sum.back());
            cout<<output<<"\n";
        }
        if(type==3){
            output=min[input-1];
            max.push_back(max.back());
            min.push_back(min.back());
            sum.push_back(sum.back());
            cout<<output<<"\n";
        }
        if(type==4){
            output=sum[input-1];
            max.push_back(max.back());
            min.push_back(min.back());
            sum.push_back(sum.back());
            cout<<output<<"\n";
        }
    }
    return 0;
}