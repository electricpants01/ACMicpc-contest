#include <bits/stdc++.h>
#include <string>
using namespace std;
// c++ -std=c++11 bdiez.cpp bdiez
// deducimos formula matematica x = (95*n - 10m) / 5 
// n es tamaño del vector, m es la suma del vector

long long int suma(vector<int> vec){
int len = vec.size();
long long int r = 0 ;
for(int i = 0 ; i < len ; i++) r += vec[i];
return r;
}

int main(){

vector<int> vec;
long long int n,m,dd;
string cad;
int g = 4;
while( getline(cin,cad)){ 
 int len = cad.length();
 string str = "";
 for(int i = 0 ; i < len ; i++){
  if( cad[i] != ',')  str += cad[i];
  else{
   stringstream ss(cad);
   ss >> dd;
   vec.push_back(dd);  str = ""; i++;   
  }
  if( i == (len-1) ){
  stringstream ss(cad);
  ss >> dd;
  vec.push_back(dd);
  }
 }
// tenemos los numeros en el vector "vec"
len = vec.size();
m = suma(vec);
double r = (m/len);
if( r >= 9.5) cout<<0<<endl;
else{
n = (95*len - 10*m)/5;
cout<<n<<endl; 
}
vec.clear();
}
return 0;
}