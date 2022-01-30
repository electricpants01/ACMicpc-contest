#include <bits/stdc++.h>
using namespace std;

string convert(int d ){
 stringstream ss;
 ss << d;                  
 string cad = ss.str();
 if(cad.length() == 1) return "0"+cad;
 return cad;
}

int main(){   
string cad;               
int n,c;
int a,b;
int sum = 0;
cin>> n >> c;
for(int i = 0 ; i < n ; i++){
 cin>>cad;
 string aux1 = cad.substr(0,1);
 string aux2 = cad.substr(2);
 istringstream(aux1) >> a;
 istringstream(aux2) >> b;
 a = a*60 + b;
 sum += a;
}
sum = sum - (n-1)*c;
int sec = sum % 60;
int minu = sum / 60;
int hora = minu / 60;
minu = minu % 60;
string sec1 = convert(sec);
string minu1 = convert(minu);
string hour1 = convert(hora);
cout<<hour1<<":"<<minu1<<":"<<sec1<<endl;
return 0;
}