#include <bits/stdc++.h>

using namespace std;
 
int contame(string cad, int num){
 int len = cad.length();
 int cont = 0;
 for(int i = 0 ; i < len ; i++){
  if( int(cad[i] == num)) cont++;
 }
 return cont;
}

bool esTodoPar(vector<int> vec){
 int len = vec.size();
 for(int i = 0; i < len ; i++){
  if( vec[i] % 2 != 0) return false;
 }
 return true;
}

bool esTodoImpar(vector<int> vec){
 int len = vec.size();
 for(int i = 0 ; i < len ; i++){
  if( vec[i] % 2 == 0) return false;
 }
 return true;
}

int main(){

 set<int> myset;
 vector<int> vec;
 string cad;
 cin>>cad;
 int len = cad.length();
 for(int i = 0 ; i < len ; i++){
  myset.insert(int(cad[i]));
 }
 for(set<int>::iterator it = myset.begin() ; it != myset.end(); it++){
  vec.push_back(contame(cad,*it));
 }
 string choose = ( vec[0] % 2 == 0)? "par" : "impar";
 bool ban;
 if( choose == "par"){
  ban = esTodoPar(vec);    
 }
 if( choose == "impar"){
  ban = esTodoImpar(vec);
 }
 if( choose == "par"){
  if( ban ) cout<<"0"<<endl;
  else cout<<"2"<<endl;
 }
 if( choose == "impar"){
  if( ban ) cout<<"1"<<endl;
  else cout<<"2"<<endl;
 }  
 return 0;
}