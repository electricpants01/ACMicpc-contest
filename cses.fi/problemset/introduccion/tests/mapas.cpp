#include <bits/stdc++.h>

using namespace std;


int main(){

map<char,int> mp;
mp['a'] = 5;
mp['z'] = 2;
for( map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
 cout<<it->first<<" -> "<<it->second<<endl;
}

return 0;
}