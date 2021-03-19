#include <bits/stdc++.h>
using namespace std;

int main(){
string cad;
ifstream arch("text.txt");
while( !arch.eof() ){
 getline(arch,cad);
 cout<<cad<<endl; 
}
arch.close();
return 0;
}