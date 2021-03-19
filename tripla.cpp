#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
ios::sync_with_stdio(0); cin.tie(0);
int arr[] = {4, 4, 4, 4, 6, 3, 4, 2, 1, 1, 4, 4, 6, 2, 4, 1, 2, 0, 4, 4, 0, 2, 2, 2, 5, 8, 8, 1, 0, 6, 8, 0};
int n = sizeof(arr)/sizeof(int);
int ans = 0;
int valor = 12;
for(int i =0; i<=n-3;i++){
    if( arr[i] + arr[i+1] + arr[i+2] == valor) ans++;
}
cout<<"ans es "<<ans<<endl;
return 0;
}
