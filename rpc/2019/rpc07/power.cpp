#include  <bits/stdc++.h>


using namespace std;


int main(){

int n;
cin>>n;
int power =  !(n & (n-1));
if(power) cout<<"N es potencia de 2"<<endl;
else cout<<"Tu dato no es potencia de 2"<<endl;
 return 0;
}