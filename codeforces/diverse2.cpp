#include <bits/stdc++.h>

using namespace std;

int main(){

 int n ;
 string s;
 vector<int> v1;
 cin>>n;
 while(n--){
 cin>>s;
 int len = s.length();
 for(int i = 0 ; i< len ; i++){
  v1.push_back(s[i]);
 }
// for(int i = 0 ; i < len ; i++ ){cout<<v1[i]<<" "; }
// cout<<endl;
 sort(v1.begin(),v1.end());
 bool ban = true;
 int ant = v1[0];
 for(int i = 1 ; i < len ; i++){
  if( ant != v1[i]-1 ){ ban = false; break;}
  ant = v1[i];
 }
 if(ban) cout<<"Yes\n";
 else cout<<"No\n";
 v1.clear();
 }
 return 0;
}