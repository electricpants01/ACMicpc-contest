#include <bits/stdc++.h>

using namespace std;

int main(){

set<int> myset;
int n,d;
cin>>n;
while(n--){
 cin>>d;
 myset.insert(d);
}
int r = myset.size();
cout<<r<<endl;
return 0;
}
