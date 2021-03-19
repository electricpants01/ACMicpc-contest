#include <bits/stdc++.h>
//https://www.titancod.net/problema/ANGULOS

using namespace std;

// en este algoritmo ocupo pitagoras
//por q solo se sabe q un triangulo tiene un angulo recto 
// cuando a^2 + b^2 = c^2

int main(){
 long long int n,a,b;
 cin>>n;
 vector<pair<long long int,long long int> > vec;
 while(n--){
  for(int i = 0 ; i < 3 ; i++){
     cin>>a;
     cin>>b;
     vec.push_back(make_pair(a,b));  
  }
  vector<long double> dist;    
  int len = vec.size();
  for( int i = 0 ; i < len ; i++){
   for(int j = i+1 ; j < len ; j++){
    long long int x1,y1,x2,y2;
    x1 = vec[i].first;
    y1 = vec[i].second;
    x2 = vec[j].first;
    y2 = vec[j].second;
    long double d = sqrt(abs(x2-x1)*abs(x2-x1) + abs(y2-y1)*abs(y2-y1)); // obtengo la longitud entre los puntos P1 P2, P1 P3, P2 P3
    dist.push_back(d);
   }
  }
   sort(dist.begin(),dist.end()); // ordenamos y deducimos q la hipotenusa es la mas grande osea dist[2]
   long double p = sqrt((dist[0] * dist[0]) + (dist[1]*dist[1]));
   if( p == dist[2]) cout<<"SI"<<"\n";
   else cout<<"NO"<<"\n";
   vec.clear();
   dist.clear(); 
 }
 return 0;
}