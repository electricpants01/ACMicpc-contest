#include <bits/stdc++.h>

using namespace std;

void split(const string &cad, char del){
stringstream ss(cad);
string p;
while( getline(ss,p,del)){
 cout<<p<<endl;
}
}
int main(){

split("hola mundo",' ');
return 0;         
}