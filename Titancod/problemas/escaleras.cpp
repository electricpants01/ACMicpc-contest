#include <bits/stdc++.h>

using namespace std;


void mostrar(vector<int> & vec){
 int len = vec.size();
 for(int i = 0 ; i < len ; i++ ) cout<<vec[i]<<" ";
 cout<<endl;
}
int main(){
int c,n,d;
vector<int> vec,orden;
cin>>c;
while(c--){
 cin>>n;
 int sum = 0 ;
 for(int i = 0 ; i < n ; i++){ cin>>d; vec.push_back(d);}
 for(int i = 0 ; i < n ; i++){
  if( vec[i] > (i+1)) sum += vec[i] - (i+1);
 }
 cout<<sum<<endl;
 vec.clear();
}
return 0;
}