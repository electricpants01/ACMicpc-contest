#include <bits/stdc++.h>


using namespace std;


int main(){
                        
int t;
long long int a,b;
cin>> t;
while( t--){
cin>> a >> b;
if( b > a ){
 long long int aux = a;
 a = b;
 b = aux;  
} // a sera mayor que b 	
while( a > 0 && b > 0 && a != b && a != b+1){
int diff = ( a - b ) / 2;
a = a - (diff * 2);
b = b - diff;
}
// ahora puede quedar en lo siguientes casos : a == b || a == b+1
if ( a > b ) { a -= 2 ; b--;}
// fin de los casos
if( a >= 0 && b >= 0){
 if( a == b && a % 3 == 0) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}else cout<<"NO"<<endl; 
}
return 0;
}