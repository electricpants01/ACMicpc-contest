#include <bits/stdc++.h>


using namespace std;


int main(){
 cin.precision(20);z
 long long int cantimpar = 0, cantzero = 0, r = 0, n,d;
 vector<long long int> vec;
 cin>>n;
 long long int len = n; 
 while( n-- ){ cin>>d; vec.push_back(d); }
 for(long long int i = 0 ; i < len ; i++ ){
  if( vec[i] > 0 ) r += vec[i]-1;
  else if( vec[i] < 0 ){
   r += vec[i]*(-1) -1;
   cantimpar++;
  }
  else if( vec[i] == 0 ) cantzero++; 
 } 
 if( cantimpar % 2 != 0 && cantzero == 0 ) r +=2;
 else r += cantzero;
 cout<<r<<endl; 
 return 0;
}