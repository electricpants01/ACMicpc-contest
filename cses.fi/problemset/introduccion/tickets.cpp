#include <bits/stdc++.h>
using namespace std;

int busqueda(int vec[], int len, int key){
 int i = 0;
 int j = len;
 int anterior;
 while( i <= j ){
    anterior = j;
    int mid = (i+j)/2;
    if( vec[mid] == key ) return mid;
    else if( vec[mid] > key) j = mid -1;
    else i = mid +1;
 }
 return anterior;
}

int main(){
int n,m,j;
cin>> n>> m;
int tickets[n+1];
int customers[m+1];
bool vendidos[n+1];
for(int i = 0 ; i < n; i++) vendidos[i] = false;
for(int i = 0 ; i < n; i++) cin>>tickets[i];
for(int i = 0 ; i < m; i++) cin>>customers[i];
sort(tickets,tickets+n);
for(int i = 0 ; i < m; i++){
    j = busqueda(tickets,n-1,customers[i]);
    while( j >= 0){
        if( j == 0 && vendidos[j] == true ) cout<<"-1"<<endl;
        if( tickets[j] <= customers[i] && vendidos[j] == false){
        cout<<tickets[j]<<endl;
        vendidos[j] = true;
        break;
        }
        j--;
    }
}
return 0;
}
