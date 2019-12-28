#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55],mod=1000000007;

int solver(string a, string b, string c, int x, int y, int z){
    if(z == 0){
        return 1;
    }

    if(x <= 0 && y <= 0){
        return 0;
    }

    if(dp[x][y][z] != -1){
        return dp[x][y][z];
    }

    int w = 0;
    for(int i = x-1 ;i >= 0; i--){
        if(a[i] == c[z-1]){
            w = (w + solver(a, b, c, i, y, z-1)) % mod;
        }
    }
    for(int i = y-1 ;i >= 0; i--){
        if(b[i] == c[z-1]){
            w = (w + solver(a, b, c, x, i, z-1)) % mod;
        }
    }
    dp[x][y][z] = w;
    return w;
}

int solve(string a, string b, string c){
    memset(dp,-1,sizeof dp);
    return solver(a, b, c, a.length(),b.length(),c.length());
}

int main(){
    string A, B, C;
    cin >> A >> B >> C;
    int ans = solve(A, B, C);
    cout << ans << endl;
}