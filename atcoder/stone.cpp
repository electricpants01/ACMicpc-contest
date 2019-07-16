#include <bits/stdc++.h>


using namespace std;

// https://tenka1-2019.contest.atcoder.jp/tasks/tenka1_2019_c


int main(){
 long long int n;
 string cad;
 cin>>n;
 cin>>cad;
 long long int aux = n-1;
 long long int sum = 0 ;
 while(aux >= 0){
  if(cad[aux] == '#' && aux != (n-1)  ){
   long long int i = aux+1;
   if(cad[i] == '.') sum++;
  }
  aux--;
 }
 cout<<sum<<endl;
 return 0;
}