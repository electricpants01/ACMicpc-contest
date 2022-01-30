#include <bits/stdc++.h>

using namespace std;

void mostrar(vector<int> vec){
 int len = vec.size();
 for(int i = 0 ; i < len ; i++) cout<<vec[i]<<" ";
 cout<<"\n";
}

int main(){

int n,x,d;
int cont = 0;
vector<int> vec;
cin>> n >> x;
while(n--){
 cin>>d;
 vec.push_back(d); 
}
sort(vec.begin(),vec.end());
mostrar(vec);
int len = vec.size();
for(int i = 0 ; i < len; i++){
 if( vec[i] != -1){
  d = vec[i]; 
  for(int j = len -1; j > i ; j--){
   cout<<"d es "<<d<<endl;
   cout<<"vec["<<j<<"] es "<<vec[j]<<endl;
   if( vec[j] != -1 ){
   if( d + vec[j] == x ){
    vec[j] = -1; cont++; break;
   }else if( d + vec[j] < x ){
    d += vec[j]; vec[j] = -1;
   }else{
    if( d <= x ) cont++;
    break;
   }
   }   
  }
 }
}
cout<<cont<<"\n";
return 0;
}