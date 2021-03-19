#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int d){
 if(d == 0 || d == 1 ) return 1;
 else return (d * factorial(d-1));
}

long long int combinatoria(long long int n,long long int k){
 long long int f = ( n - k < k ) ? n-k : k;
 long long int r = 1;
 for(int  i = 1; i <= f; i++){
  r = r * n; n--;
 }
 r = r/factorial(f);
 return r;
}

vector< vector<int> > generate(int numRows) {
 vector< vector<int> > vec; int d;
 vector<int> v;
 for(int i = 1; i <= numRows ; i++){
  for(int j = 1 ; j <= i; j++){
   if(j == 1 || j == i ) v.push_back(1);
   else{
    d = vec[i-1][j-2] + vec[i-1][j-1];
    cout<<"d es "<<d<<endl; 
    v.push_back(d);
   }
  }
  vec.push_back(v);
  v.clear();
 }
 return vec;        
}

void mostrar(vector<vector<int> > vec){

}

int main(){

vector<vector<int> > vec = generate(3);
cout<<"len es : "<<vec.size();                      
return 0;
}