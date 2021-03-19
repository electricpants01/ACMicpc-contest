#include <bits/stdc++.h>

using namespace std;

long long int contar(bool vec[], long long int n){
 long long int len = 0;
 for( long long int i = 1 ; i <= n ; i++){
  if( vec[i] ) len++;
 }
 return len;
}

void mostrar1(bool vec[],long long int n){
 for(long long int i = 1 ; i <= n ; i++){
  if( vec[i] ) cout<<i<<" ";
 }
 cout<<"\n";
}

void mostrar2(vector<long long int> vec){
 long long int len = vec.size();
 for(long long int i = 0 ; i < len ; i++){
  cout<<vec[i]<<" "; 
 }
 cout<<"\n";
}

int main(){
 
 long long int n;
 cin>>n;
 bool vec[n+1];
 for(long long int i = 1 ; i <= n ; i++) { vec[i] = true;}
 vector<long long int> myvec;
 long long int cant = (n) * (n+1) / 2; 
 if( cant % 2 != 0) cout<<"NO"<<endl;
 else{
  cant = cant/2;
  for( long long int i = n ; i >= 1 ; i--){
   if( cant - i >= 0){
    myvec.push_back(i);
    vec[i] = false;
    cant -= i;    
   }
  }    
  cout<<"YES"<<endl;
  cout<<contar(vec,n)<<endl;
  mostrar1(vec,n);
  cout<<myvec.size()<<endl;
  mostrar2(myvec);   
 } 
 return 0;
}