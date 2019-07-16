#include <bits/stdc++.h>


using namespace std;


int comparar(vector<int> vec1, vector<int> vec2,int dias){
 int len = vec1.size();
 int a = 0; bool ban = false; int empate = 0;
 for(int i = 0 ; i < len ; i++){
  if( vec1[i]+dias > vec2[i]) { ban = true; a++; }
  if( vec1[i]+dias == vec2[i]) { empate++; }  
 }
 if(ban || empate == len) a+= empate;
 return a;
}

int main(){

 vector<int> vec1,vec2;
 long long sum1 = 0,sum2 = 0,dias = 0;
 int n,d;
 cin>>n;
 for(int i = 0 ; i < n;i++){
  cin>>d;
  vec1.push_back(d);  
  sum1 += d;
 }
 for(int i = 0 ; i < n;i++){
  cin>>d;
  vec2.push_back(d);  
  sum2 += d;
 } 
 // ahora hacemos un while
 if( sum1 <= sum2){
  while(sum1 < sum2){
   dias++; sum1+=n;
  }
  while( comparar(vec1,vec2,dias) != n){
  dias++;
 }
 }
 cout<<dias<<endl;           
 return 0;
} 