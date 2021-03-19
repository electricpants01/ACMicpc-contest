#include <bits/stdc++.h>
using namespace std;
 
void mod(int a[][100]){
 a[0][0] = -1;
 cout<<"dato antiguo "<<a[0][0]<<endl;
}                                     

int main(){
 int a[100][100];
 for(int i = 0 ; i < 5; i++){
  for(int j =0; j < 5; j++){
   a[i][j] = rand() % 10 +1;
  }
 } 
 mod(a);
 cout<<"dato antiguo "<<a[0][0]<<endl;                                     
 return 0;
}
