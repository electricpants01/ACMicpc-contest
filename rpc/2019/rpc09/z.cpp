#include <bits/stdc++.h>

using namespace std;

int main(){

int r[100][100];   
r[1][1] = 1;
r[1][2] = 2;
r[2][2] = 15;
r[2][3] = 20;
r[3][1] = 30;
r[3][3] = 10;
for( int i = 1; i < 5; i++){
 for(int j = 1; j < 5; j++){
  cout<<r[i][j]<<" ";
 }
 cout<<endl;
}
return 0;
}