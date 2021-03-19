#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
ios::sync_with_stdio(0); cin.tie(0);
int arr[] = {1, 2, 0, 1, 1, 1, 2, 0, 1, 0, 0, 3};
int n = sizeof(arr)/sizeof(int);
int ans = 0;
int valor = 3;
for(int i =0; i<=n-3;i++){
    if( arr[i] + arr[i+1] == valor || arr[i] + arr[i+1] + arr[i+2] == valor) ans++;
}
cout<<"ans es "<<ans<<endl;
return 0;
}
