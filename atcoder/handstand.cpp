#include <bits/stdc++.h>

//https://atcoder.jp/contests/abc124/tasks/abc124_d

using namespace std;

int main(){
 long long int n,d;
 string cad;
 cin>>n;
 cin>>d;
 cin>>cad;
 vector<long long int> vec;
 long long int sum = 0,r = 0,dd;
 for(long long int i = 0 ; i < n ; i++){
   dd = d; sum = 0;
  for(long long int j = i ; j < n ; ){
    if( cad[j] == '0' && dd == 0) break;
    r = 0;
    if(cad[j] == '1'){sum++; j++;}
    if( cad[j] == '0' && dd > 0 ){
     while(cad[j] == '0'){
      r++; j++;
     }
    dd--;
    }
   sum += r;
   }
   vec.push_back(sum);
  }
 sort(vec.begin(),vec.end()); 
 cout<<vec[vec.size()-1]<<endl;
 return 0;
}