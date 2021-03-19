#include <bits/stdc++.h>


using namespace std;


int main(){

 long long int n;
 cin>>n;
 vector<long long int > vec;
 if( n != 2 && n != 3){
  for(long long int i = n-1 ; i > 0 ; i -= 2){ vec.push_back(i);}
 for(long long int i = n ; i > 0 ; i -= 2){ vec.push_back(i);}    
 }
 if( vec.size() == n ) {
  for(long long int i = 0 ; i < n ; i++){
   cout<<vec[i]<<" ";
  }
  cout<<"\n";
 }else cout<<"NO SOLUTION"<<endl;
 return 0;
}