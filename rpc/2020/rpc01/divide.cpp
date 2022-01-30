#include <bits/stdc++.h>
using namespace std;

int main(){

double n,m,sum = 0;
vector<double> vec;
cin>> n >> m; // leo los datos
for(int i = 0 ; i < n ; i++){int d; cin>>d; vec.push_back(d); sum+= d;} // suma total
double solved = m / sum; // valor x cada problema resuelto
for(int i = 0; i < n ; i++) { cout<<vec[i]*solved<<endl; }
return 0;
}
