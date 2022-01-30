#include <bits/stdc++.h>
using namespace std;

void mod(int vec[]){
 vec[0] = 100;
 vec[5] = 200;
}

int main(){

 int vec[] = {1,2,3,4,5,6};
 mod(vec);
 cout<<vec[0]<<endl;
 cout<<vec[5]<<endl;
return 0;
}
