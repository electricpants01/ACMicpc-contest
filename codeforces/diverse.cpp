#include <bits/stdc++.h>

using namespace std;


int main(){
 int n;
 string cad;
 cin>>n;
 while(n--){
 cin>>cad;
 int len = cad.length();
 vector<int> vec;
 for(int i = 0 ; i < len ; i++){
   vec.push_back(int(cad[i]));
  }
 sort(vec.begin(),vec.end());
// for(int i = 0 ; i < len ; i++) cout<<vec[i]<<" ";
 int a = vec[0];
 bool ban = true;
 for(int i = 1 ; i < len ; i++){
  if( a+1 != vec[i]){    	
    ban = false;    
   }
  a = vec[i];
  }
  if(ban) cout<<"YES\n";
  else cout<<"NO\n";
  vec.clear();
 }
 return 0;
}