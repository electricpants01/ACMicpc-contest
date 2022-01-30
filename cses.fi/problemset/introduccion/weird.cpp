#include <bits/stdc++.h>


using namespace std;

int main(){

 long long int n;
 cin>>n;
 bool ban = true;
 while( ban ){
  if( n == 1 ) ban = false;
  cout<<n<<" ";
  if( n % 2 == 0 ) n /= 2;
  else n = n * 3 + 1;
 }
 cout<<endl;
 return 0;
}