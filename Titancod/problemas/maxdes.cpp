#include <bits/stdc++.h>

using namespace std;

void rellenar(vector<int> &vec, int a, int b){
 for(int i = a; i <= b ; i++) vec.push_back(i);
}

void mostrar(vector<int> vec){
 int len = vec.size();
 for(int i = 0 ; i < len ; i++) cout<<vec[i]<<" ";
 cout<<endl;
}

int main(){

int n,m;
vector<int> vec;
cin>>n;
while(n--){
 cin>>m;
 if(m % 2 == 0){
  int sum = 0,a = 1;
  for(int i = a ; true ; i++){
   if( sum < m) sum += i;
   else{
    if( sum == m ){
     rellenar(vec,a,i-1); break;// rellenamos el vector
    }else if( a < m-1){ a++; i = a-1; sum = 0;}
    else break;
   }
  }
  if( sum == m) mostrar(vec);
  else cout<<"-1\n";
 }else{
  int d = (m/2);
  cout<<d<<" "<<d+1<<endl;
 }
 vec.clear();
}
return 0;
}