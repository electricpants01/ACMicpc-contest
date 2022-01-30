#include <bits/stdc++.h>
using namespace std;

int main(){
int n, amt;
vector<int> vec;
double sum = 0;
cin>> n >> amt;
for(int i = 0 ; i < n ; i++){ int d; cin>>d; vec.push_back(d); sum+=d;} // los datos en el vector
double cant = amt/sum;
for(int i = 0 ; i < n ; i++){
 cout<<cant*vec[i]<<endl;
}

return 0;
}