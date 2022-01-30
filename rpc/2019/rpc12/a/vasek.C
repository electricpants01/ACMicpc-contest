#include <iostream>
#include <cassert>
using namespace std;
typedef long long int ll;

#define MOD 1000000007ll

int main(){
    ll A,B,K,C;
    cin>>A>>B>>K>>C;
    assert(1<=A && A<=9);
    assert(1<=B && B<=9);
    assert(1<=C && C<=9);
    assert(0<=K && K<=1000);
    ll p=K; for(int i=0; i<K-1; ++i)p=(p*2)%MOD;
    ll res=0;
    if(C==A || C==B){
        if(A==B){
            res=1;
        }else{
            res=p;
        }
    }else {
        res=0;
    }
    cout<<res<<endl;
}

