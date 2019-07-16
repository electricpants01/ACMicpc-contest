#include <set>
#include <iostream>

// este algoritmo es eficiente (mas o menos)
// usando el ED set, podemos comparar dos arrays para saber que elementos en comun tienen

using namespace std;


int main(){
 
 set<int> miset;
 int vec[5] = {1,2,3,0,-2};
 for(int i = 0 ; i<5;i++){
  int d;
  cin>>d;
  miset.insert(d);
 }
 for(int i= 0 ; i< 5; i++){
  if( miset.count(vec[i])) cout<<vec[i]<<" ";
 }
 cout<<endl;
 return 0;
}
