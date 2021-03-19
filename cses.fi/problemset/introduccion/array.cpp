#include <bits/stdc++.h>


using namespace std;

long long int mayor1(vector<long double> vec,long long int maximo){
 long long int mayor = vec[0];
 long long int r = 0;
 long long int len = vec.size();
 for(long long int i = 0 ; i < maximo ; i++){
  if( mayor < vec[i] ){
   mayor = vec[i];
   r = i;
  }
 }
 return r;
} 

int main(){
 cout.precision(15);
 long double r = 0 ,n; 
 cin>>n;
 vector<long double > vec(n);
 for(long double i = 0 ; i < n ; i++){
  cin>>vec[i];
 } 
 long long int mayor = mayor1(vec,n);
 long long int b = n - 1;
 while( mayor >= 0 ){
  while( b >= mayor ){
   r += vec[mayor] - vec[b];
   b--;
  }  
  b = mayor-1; 
  if( b < 0 ) break;
  mayor = mayor1(vec,b);
 }
 cout<<r<<endl;
 return 0;
}