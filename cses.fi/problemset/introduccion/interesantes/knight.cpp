// algoritmo interesante
// On-line encyclopedia of integer sequence
// http://oeis.org/search?q=0%2C6%2C28%2C96%2C252%2C550%2C1056&sort=&language=german&go=Suche
// libro http://members.chello.cz/kotesovec/kotesovec_non_attacking_chess_pieces_2013_6ed.pdf

#include <bits/stdc++.h>


using namespace std;


int main(){
 cout.precision(20);
 int n;
 cin>>n;
 long double r;
 for( long double i = 1 ; i <= n; i++){
  r = (i-1)*(i+4)*(i*i - 3*i + 4);
  r /= 2;
  cout<<r<<endl;
 }
 return 0;
}