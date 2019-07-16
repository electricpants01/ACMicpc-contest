#include <iostream>
#include <fstream>


using namespace std;

int main(){

 fstream arch;
 arch.open("hola.txt",ios::out);
 int n;
 cout<<"cuantas lineas quieres escribir ";
 cin>>n;
 while(n--){
  string cad;
  cin>>cad;
  arch<<cad<<endl;
 }
 return 0;
}