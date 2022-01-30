#include <bits/stdc++.h>
#define ll long long int;
using namespace  std;

void solveB(){
  int r,c; cin >> r >> c;
  bool ans = true;
  long long int arr[r][c];
  for(int i=0; i<r;i++){
    for(int j=0; j<c; j++) cin >> arr[i][j];
  }
  for(int a=0; a<r-1;a++){
    for(int b=0; b<c-1;b++){
      int i=a,i2=a+1,j=b,j2=b+1;
      if( arr[i][j] + arr[i2][j2] > arr[i2][j] + arr[i][j2] ){
        ans = false;
//        cout<<arr[i][j]<<" "<<arr[i2][j2]<<" ";
//        cout<<arr[i2][j]<<" "<<arr[i][j2]<<endl;
      }
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

void solveC(){
  vector<pair<long long int, long long int>> v;
  int n; cin >> n;
  for(int i=0; i<n;i++){
    long long int a, b; cin >> a >> b;
    v.emplace_back(a,b);
  }//
  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        if((v[j].first-v[i].first)*(v[k].second-v[i].second)-(v[k].first-v[i].first)*(v[j].second-v[i].second)!=0){ans++;}
      }
    }
  }
  cout<<ans<<endl;
}

int main() {
  cin.tie(0);
  solveC();
  return 0;
}
