#include <bits/stdc++.h>

using namespace std;

int main(){

int n,m,d,k;
vector<int> vec;
while( cin >> k){
 for(int i = 0 ; i < k ; i++){ cin>>d; vec.push_back(d);}
 cin>>m;
 sort(vec.begin(),vec.end());
 int a,b;
 int len = vec.size();
 bool ban = true;
 for( int j = len-1; j >= 0 && ban ; j--){
  for( int i = 0 ; i < j  && ban; i++){
   if( (vec[i] + vec[j]) == m ) { a = i; b = j; ban = false; }
   if( vec[i] + vec[j] > m ) break;
  }
 }
 if( ban == false ) cout<<vec[a]<<" "<<vec[b]<<endl;
 else cout<<"-1\n";
 vec.clear();
} 
}