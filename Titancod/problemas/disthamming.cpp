#include <bits/stdc++.h>

using namespace std;

int main(){

int n;
string cad,str;
cin>>n;
while(n--){
 int cont = 0;
 cin>>cad;
 cin>>str;
 int len = cad.length();
 for(int i = 0 ; i < len ; i++){
  if(cad[i] != str[i]) cont++;
 }
 cout<<cont<<endl;
}
return 0;
}