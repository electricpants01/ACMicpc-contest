#include <bits/stdc++.h>
using namespace std;

int busqueda(vector<int> vec, int len, int key){
 int i = 0;
 int j = len;
 int anterior = j;
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

int n,m,d,j;
vector<int> mytickets,frecuencias;
cin >> n >> m;
int tickets[n+1];
int customers[m+1];
// insersion de datos
for(int i = 0; i < n; i++) cin>> tickets[i];
for(int i = 0; i < m; i++) cin>>customers[i];
sort(tickets,tickets+n);
d = 0;
for(int i = 0; i < n;){
    int r = tickets[i];
    mytickets.push_back(tickets[i]);
    frecuencias.push_back(0);
    while( i < n && r == tickets[i] ){
        frecuencias[d]++;
        i++;
    }
    d++;
}
// fin de la insersion
int len = mytickets.size();
for(int i = 0; i < m ; i++){
    j = busqueda(mytickets,len-1,customers[i]);
    while( j >= 0){
        if( j == 0 && ( frecuencias[j] == 0 || mytickets[j] > customers[i] )) cout<<"-1"<<endl;
        if( frecuencias[ j ] > 0 && mytickets[ j ] <= customers[i] ){
            cout<<mytickets[j]<<endl;
            frecuencias[ j ] = frecuencias[ j ] - 1;
            break;
            }
        j--;
    }
}

return 0;
}
