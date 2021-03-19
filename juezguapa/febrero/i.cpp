#include <bits/stdc++.h>

using namespace std;

int main(){

int n,k;
int d;
set<int> myset;
cin>> n >> k;
for(int i = 0 ; i < n ; i++){ cin>>d; myset.insert(d);}
for(set<int>::iterator it = myset.begin(); it != myset.end(); it++){ cout<<*it<<" ";}
cout<<endl;
return 0;
}