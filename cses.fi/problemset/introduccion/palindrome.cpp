#include <bits/stdc++.h>

using namespace std;


int main(){

map<char,int> mp;
string cad;
cin>>cad;
int len = cad.length();
for(int i = 0; i < len; i++) mp[cad[i]]++;
for(map<char,int>::iterator it  = mp.begin(); it != mp.end() ; it++){
 cout<<it->first <<"  second = "<< it->second<<endl; 
}
return 0;
}