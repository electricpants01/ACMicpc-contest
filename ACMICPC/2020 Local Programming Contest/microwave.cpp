//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    char temp; int h, m;
    scanf("%2d %1c %2d",&h,&temp,&m);
    int total_segundos = (3600*h + 60*m) - (60*h + m);
    int hours = total_segundos / 3600;
    int segundos = total_segundos % 60;
    total_segundos /= 60;
    int minutos = total_segundos % 60;
    printf("%d:%d:%d", hours,minutos,segundos);
    return 0;
}

