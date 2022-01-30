#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;


int main(){

int d,arr[1001], j = 1, len;
string cad,str = "";
long long int res = 0;
for(int i = 1 ; i <= 1000 ; i++) arr[i] = -1;
while( cin>> cad){
 int comma = cad.find_first_of(",");
 if( comma != -1 ){
  for(int i = 0 ; i < comma; i++) str += cad[i];
  arr[j] = atoi(str.c_str()); 
  len = cad.length() - 1 - cad.find_first_of("-");
  res += arr[j] *( ( len == 0) ? 1 : len );  
 }else{
  res += cad.length() * 42;
 } 
 // 
 str = ""; j++;
}
res = (res+9)/10*10;
cout<<res<<",-"<<endl;
return 0;
}