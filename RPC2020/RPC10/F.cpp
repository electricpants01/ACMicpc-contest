#include<bits/stdc++.h>
using namespace std;
long long int ways[101][101][101];

int main()
{
    string w1,w2,w3,full;
    cin >> w1 >> w2 >> w3 >> full;
    int MOD = 1e9+7;
    ways[0][0][0] = 1;
    for(int i=0; i <= w1.length(); i++){
        for(int j=0; j<= w2.length(); j++){
            for(int k=0; k<= w3.length(); k++){
                ways[i][j][k] %= MOD;
                if (i != w1.length() && w1[i] == full[i + j + k])
                    ways[i + 1][j][k] += ways[i][j][k];
                if (j != w2.length() && w2[j] == full[i + j + k])
                    ways[i][j + 1][k] += ways[i][j][k];
                if (k != w3.length() && w3[k] == full[i + j + k])
                    ways[i][j][k + 1] += ways[i][j][k];
            }
        }
    }
    cout<<ways[w1.length()][w2.length()][w3.length()]<<endl;
    return 0;
}
