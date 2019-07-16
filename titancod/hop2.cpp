#include <bits/stdc++.h>
// https://www.titancod.net/problema/ULTESPERAN

using namespace std;


int main(){

 int n,coor,x1,y1,x2,y2,r;
 cin>>n;
 while(n--){
  cin>>coor;
  vector<pair<int,int> > vec;
  for(int i= 0 ; i< coor ; i++){
   cin>>x2;
   cin>>y2;
   vec.push_back(make_pair(x2,y2));
  }
  cin>>x1;
  cin>>y1;
  cin>>r;
  int sum = 0;
  int len = vec.size();
   for( int x = 0 ; x < len ; x++){
    int a = vec[x].first;
    int b = vec[x].second;
    double d = sqrt(abs((a - x1)*(a - x1)) + abs((b - y1)*(b - y1)));
    if( d <= r ) sum++;
   }
   cout<<sum<<"\n";
   vec.clear();
  }
 return 0;
}    
 
