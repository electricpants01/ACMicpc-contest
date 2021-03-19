#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
ios::sync_with_stdio(0); cin.tie(0);
int arr[] = {4, 7, 7, 1, 3, 0, 2, 8, 5, 7, 0, 3, 8, 7, 3, 4, 3, 5, 3, 4, 8, 0, 5, 1, 2, 7, 4, 8, 6, 7, 3, 6};
int n = sizeof(arr)/sizeof(int);
int ans = 0;
int valor = 11;
for(int i =0; i<=n-2;i++){
    if( arr[i] + arr[i+1] == valor) ans++;
}
cout<<"ans es "<<ans<<endl;
return 0;
}
