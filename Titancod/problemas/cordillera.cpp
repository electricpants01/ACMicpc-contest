#include <bits/stdc++.h>

using namespace std;

int main(){

int n,m,d;
vector<int> vec;
cin>> n;
while(n--){
 cin>>m;
 int cont = 0;
 for(int i = 0 ; i < m ; i++){ cin>>d; vec.push_back(d); }
 for(int i = 0 ; i <= m-3; i++){
 if( vec[i] < vec[i+1] && vec[i+1] > vec[i+2]){
   cont++; i++;
  }
 }
 cout<<cont<<endl;
 vec.clear();
}
return 0;
}