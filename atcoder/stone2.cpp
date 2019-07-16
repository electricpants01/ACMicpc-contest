#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
  int N;
  cin >> N; 
  char inp;
  int b,w; b=w=0;
  int count=0;
  for(int i=0; i<N; i++){
    cin >> inp;
    if('.'==inp){
      if(b>0){w++;}
    }
    else{
      if(b>0 && b<w){count=count+b; b=w=0;}
      b++;
    }
  }
  
  cout << count + min(w,b);
  
  return 0;
}