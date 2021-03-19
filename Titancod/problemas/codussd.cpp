#include <bits/stdc++.h>

using namespace std;

int main(){

int n;
string cad;
cin >> n;
while(n--){
 cin>>cad;
 bool ban = true;
 int len = cad.length();
 if( cad[0] == '*' && cad[len-1] == '#'){
  for(int i = 1 ; i < 4 ; i++){
   if( ! isdigit(cad[i]) ) ban = false;
  }
  if(cad[4] != '*') ban = false;
  for( int i = 5; i < len -1; i++){
   if( ! isdigit(cad[i]) ) ban = false;
  }
 }else ban = false;
 if(ban) cout<<"bien\n";
 else cout<<"mal\n";
}
return 0;
}