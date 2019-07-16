#include <bits/stdc++.h>

// ejercicio de un grafo simple sin peso

using namespace std;

void mostrar(vector<int> vec[],int n){
 for(int i = 1 ; i <= n; i++){
  int len = vec[i].size();
  for(int j = 0; j < len ; j++){
    cout<<"desde "<<i<<" hasta "<<vec[i][j]<<"\n";
  }  
 }
}

void dfs(bool ban[],vector<int> vec[],int s){
 if(ban[s]) return;
 ban[s] = true;
 cout<<s<<" -> "; 
 for( auto x : vec[s]){
  dfs(ban,vec,x);
 }
}
int main(){

 int n,d;
 int x,y;
 cin>>n;
 vector<int> vec[n+1];
 cout<<"cuantos datos va meter : ";
 cin>>d;
 while(d--){
  cout<<"desde : ";
  cin>>x;
  cout<<"hacia : ";
  cin>>y;
  vec[x].push_back(y);   
 }
 mostrar(vec,n);
 // dfs
 bool ban[n+1];
 for(int i = 0 ;i <= n;i++){ ban[i] = false;}
 dfs(ban,vec,1);
 return 0;
}