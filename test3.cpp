#include <bits/stdc++.h>

using namespace std;



int main(){
string cad;
cin>>cad;
string f = "";
int len = cad.length();
for(int i = 0 ; i < len ; i++){
 char d = char(int(cad[i])-i);
 f+=d;
}
 cout<<f<<endl;
return 0;
}