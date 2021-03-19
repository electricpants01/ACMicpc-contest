#include <bits/stdc++.h>

using namespace std;


int main(){

 int a,b,d;
 vector<int> vec1;
 vector<int> vec2;
 cin>>a;
 while(a--){ cin>>d; vec1.push_back(d);   } 
 cin>>b;
 while(b--){ cin>>d; vec2.push_back(d);   }
 sort(vec1.begin(),vec1.end());
 sort(vec2.begin(),vec2.end());
 cout<<vec1[vec1.size()-1]<<" "<<vec2[vec2.size()-1]<<endl;
 return 0;
}