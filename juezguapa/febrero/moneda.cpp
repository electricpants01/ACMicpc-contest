#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int d){
 if(d == 0 || d == 1 ) return 1;
 else return (d * factorial(d-1));
}

long long int combinatoria(long long int n,long long int k){
 long long int f = ( n - k < k ) ? n-k : k;
 long long int r = 1;
 for(int  i = 1; i <= f; i++){
  r = r * n; n--;
 }
 r = r/factorial(f);
 return r;
}

int main(){                                              
long long int n,f;
vector<int> vec;
cin >> n;
f = n / 2; vec.push_back(1); // 1 al inico
for(long long int i = 1; i <= f; i++){
 vec.push_back( combinatoria(n,n-i) % 2 );
}
for(int  i = 0 ; i < vec.size(); i++) cout<<vec[i]<<" ";
return 0;
}