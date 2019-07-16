#include <bits/stdc++.h>

using namespace std;


void dfs(int s, bool ban[], vector< pair<int,int> > vec){
 if(ban[s]) return ;
 cout<<vec[s].first<<" -> ";
 ban[s] = true;
 for( auto x : vec[s]){
  dfs(x.first,ban,vec);
 } 
}

int main(){

 int n,a,x,y,z;
 cin>>n;
 vector< pair<int,int> > vec[n+1];
 cin>>a;
 while(a--){
  cin>>x;
  cin>>y;
  cin>>z;
  vec[x].push_back( make_pair(y,z)); 
 }
 bool ban[n+1];
 for(int i = 0 ;i <= n+1 ; i++){ ban[i] = false;}
 dfs(1,&ban,vec);  
 return 0;
}