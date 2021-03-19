#include <bits/stdc++.h>

using namespace std;

int main(){

int n,len;
string cad;
cin>>n;
while(n--){
 cin>>cad;
 len = cad.length();
 int num = 0, cant = 0,sum = 0;
 for( int i = 0 ; i < len ; i++){
  if( i < len -1){
   if( cad[i] == '1' && cad[i+1] == '0'){ sum += 10; cant++; num = 0;}
   else{
    num = int(cad[i]) -'0';
    if( num > 0 ) { sum+= num; cant++; num = 0;}
   }
  }else{
   num = int(cad[i]) - '0';
   if( num > 0 ){ sum += num; cant++; num = 0;}
  } 
 }
double r = double(sum)/double(cant);
cout<<r<<endl;
 }
return 0;
}