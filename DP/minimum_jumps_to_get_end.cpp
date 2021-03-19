#include <bits/stdc++.h>
//https://www.youtube.com/watch?v=2y_cJMXQrtA&list=PLeIMaH7i8JDjMEB-b2I8NGcKMFZc85djW&index=2
using namespace std;
#define ll long long

int main() {
    int min_jumps_arr[100];
    min_jumps_arr[0] = 0;
    for(int i=1; i< 100 ; i++) min_jumps_arr[i] = 1e9;
    int jump_path_arr[100];
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n;i++) cin>> arr[i];
    for(int i =1; i<n; i++){
        for(int j =0; j < i ; j++){
            if( i <= (j + arr[j])){
                if( (1+min_jumps_arr[j]) < min_jumps_arr[i]){
                    min_jumps_arr[i] = 1 + min_jumps_arr[j];
                    jump_path_arr[i] = j;
                }
            }
        }
    }
    for(int i =0; i<n; i++) cout<<min_jumps_arr[i]<<" ";
    return 0;
}