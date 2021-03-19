#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1090
using namespace std;

int main(){

int n,x,cont = 0;
int sum = 0;
cin >> n >> x;
int vec[n+1];
for(int i = 0; i < n ; i++) cin>>vec[i];
sort(vec,vec+n);
int j = n-1;
int i = 0;
while( i <= j){
    if( i == j){
        cont++; break;
    }
    if( vec[i] + vec[j] <= x){
        cont++; i++; j--;
    }else{
     cont++; j--;
    }
}
cout<<cont<<endl;
return 0;
}
