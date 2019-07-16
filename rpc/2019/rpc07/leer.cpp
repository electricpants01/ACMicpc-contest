#include <iostream>
#include <fstream>

using namespace std;


int main(){

 fstream leer;
 leer.open("hola.txt",ios::in);
 string cad;
 while( !leer.eof()){
  getline(leer,cad);
  cout<<cad<<endl;
 }
 leer.close();
 return 0;
}