#include <bits/stdc++.h>
/*
 * Este problema es relativamente sencillo, solo debes emular lo que dice en el problem statement
 */
using namespace std;
#define ll long long

string getExtension(string cad){
    int pos = cad.find_last_of(".");
    string ans = cad.substr( pos, cad.length() - pos );
    return ans;
}

string getName(string cad){
    int car = -1;
    for(int i=0; i<cad.length(); i++){
        if( cad[i] == '\\') car = i;
    }
    if( car != -1){
        return  cad.substr(car+1, cad.find_last_of(".") - car -1);
    }else{
        return cad.substr(0,cad.find_last_of("."));
    }
}

bool verifExtension(string ex){
    if( ex == ".cpp" || ex == ".java" || ex == ".c" || ex == ".py") return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<setprecision(12)<<fixed;
    string problem, filename;
    ll r, d, e, c, t;
    getline(cin, problem);
    getline(cin, filename);
    cout<<getName(filename)<<endl;
    cin >> r >> d >> e >> c;
    vector<string> correct, mine;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0; i<c;i++){
        string cad; getline(cin, cad);
        correct.push_back(cad);
    }
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i =0; i<t; i++){
        string cad; getline(cin ,cad);
        mine.push_back(cad);
    }
    string ex = getExtension(filename);
    if( getName(filename) != problem || ! verifExtension(ex) ){
        cout<<"Compile Error"<<endl;
    }else if( r != 0 ){
        cout<<"Run-Time Error"<<endl;
    }else if( d < e ){
        cout<<"Time Limit Exceeded"<<endl;
    }else{
        bool ans = true;
        if( t != c ) ans = false;
        else{
            for(int i=0; i<t; i++){
                if( correct[i] != mine[i]){
                    ans = false;
                    break;
                }
            }
        }
        if( ans ) cout<<"Correct"<<endl;
        else cout<<"Wrong Answer"<<endl;
    }
    return 0;
}
