#include <bits/stdc++.h>
using namespace std;

int main(){
 FILE *file;
 file = fopen("text.txt","a");
 fputs("bienvenido master \nchristian",file);
 fclose(file);
return 0;
}