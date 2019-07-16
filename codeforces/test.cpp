#include <bits/stdc++.h>

using namespace std;


int main(){
 string cad;
 cin>>cad;
 cout<<*max_element(cad.begin(),cad.end()); 
 return 0;
}