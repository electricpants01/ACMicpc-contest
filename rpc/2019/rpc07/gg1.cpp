#include <bits/stdc++.h>
// este es un ejercicio de un grafo con peso

using namespace std;


void mostrar(vector<pair<int,int> > vec[],int n){
 for(int i = 1 ; i <= n; i++){
  for(auto x : vec[i]){
   cout<<"desde "<<i<<" hasta "<<x.first<<" con un peso de "<<x.second<<endl; 
  }
 }
}
                                  
int main(){
 
 int n,a,b,p;
 cout<<"len del array ";
 cin>>n;
 vector<pair<int,int> > vec[n+1];
 int d;
 cout<<"cuantos datos desea meter : ";
 cin>>d;
 while(d--){
  cout<<"desde : "; 
  cin>>a;
  cout<<"hacia : ";
  cin>>b;
  cout<<"con un peso de : ";
  cin>>p;
  vec[a].push_back(make_pair(b,p)); 
 }
 mostrar(vec,n);
 return 0;
}