#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
 int n,d,e;
 cin>>n;
 cin>>d;
 cin>>e;
 int i = 0;     
 int sol = n % d;
 while ( i <= n ){
  sol = min( sol , (n-i) % d);
  i += 5*e;
 }
 cout<<sol<<endl;
}                                                            
