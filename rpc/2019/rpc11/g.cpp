#include <bits/stdc++.h>

using namespace std;


int contarE(string cad){
 int len = cad.length();
 return (len -2 );             
}

int main(){

 string cad;
 cin>>cad;
 string r = "h";
 int d = contarE(cad);
 for(int i = 0 ; i < d ; i++) r += "ee";
 r += "y";
 cout<<r<<endl;
 return 0;
}