#include <bits/stdc++.h>
using namespace std;

int verif(int a, int x){
    int cont = 0;
    while(a > 0 ){
        if( a % 10 == x ) cont++;
        a /= 10;
    }
    return cont;
}


int main()
{
    int a,b,x; cin >> a >> b >> x;
    int ans = 0;
    for(int i =a; i <= b ; i++){
        ans += verif(i,x);
    }
    cout<<ans<<endl;
    return 0;
}