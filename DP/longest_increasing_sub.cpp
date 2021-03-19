#include <bits/stdc++.h>
//https://www.youtube.com/watch?v=2y_cJMXQrtA&list=PLeIMaH7i8JDjMEB-b2I8NGcKMFZc85djW&index=2
using namespace std;
#define ll long long

int main() {
    int arr[100]; int n; cin >> n;
    for(int i =0; i< n; i++) cin >> arr[i];
    int length[100]; int subseq[100];
    for(int i =0; i< 100; i++ ) length[i] = 1;
    for(int i =1; i< n; i++){
        for(int j =0; j < i; j++){
            if( arr[j] <= arr[i] ){
                if( (1 + length[j]) >= length[i] ){
                    length[i] = 1 + length[j];
                    subseq[i] = j;
                }
            }
        }
    }
    // mostramos length
    for(int i =0; i< n; i++) cout<<length[i]<<" ";
    cout<<endl;
    for(int i =0; i< n; i++ ) cout<<subseq[i]<<" ";
    cout<<endl;
    return 0;
}