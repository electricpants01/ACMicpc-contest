#include <bits/stdc++.h>
// https://www.johndcook.com/blog/2015/08/04/last-digits-fibonacci-numbers/
// la ref de arriba soluciona el problema, esta basado en un teorema q se aplica en los numeros fibonacci

using namespace std;

void genfibo(long long int fibo[]){
fibo[0] = 0;
fibo[1] = 1;
for(int i = 2 ; i <= 60 ; i++){
 fibo[i] = fibo[i-1] + fibo[i-2];
}
}
int main(){

long long int fibo[61];
genfibo(fibo);      
int n,d;
cin>>n;
while(n--){
 cin>>d;
 d = d % 60;
 if( fibo[d] % 2 == 0 ) cout<<fibo[d-1]%10<<" par\n";
 else cout<<fibo[d-1]%10<<" impar\n";
} 
return 0;
}