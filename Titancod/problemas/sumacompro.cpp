#include <bits/stdc++.h>

using namespace std;

int main(){

string cad;
while( getline(cin,cad) ){
int len = cad.length();
long long int r = 0;
for(int i = 0 ; i < len ; i++){
 if( cad[i] != ' ')  r += (int(cad[i])%65) * (i+1);
}
cout<<r<<endl;
}
return 0;
}