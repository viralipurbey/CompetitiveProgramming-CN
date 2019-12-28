#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool canassign(int j, int mask, int n){
    vector<int> assigned;
    for(int i = 1; i <= n; i++){
        if(mask & (1<<i)){
            assigned.push_back(i);
        }
    }
     for(int i = 0; i < assigned.size(); i++){
        if(j & assigned[i] == j){
            return false;
        }
    }
    return true;
}

ll no_of_ways(int n, ll *dp,int mask){

    if(mask == ((1<<(n+1))-2)){
        return 1;
    }

    if(dp[mask] != -1){
        return dp[mask];
    }
    ll ans = 0;
    for(int j = 1; j <= n; j++){
        if(!(mask & (1<<j)) && canassign(j, mask, n)){  
            ans = ans + no_of_ways(n, dp, (mask | (1<<j)));
        }
    }
    dp[mask] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;

    ll *dp = new ll[(1<<(n+1))]();
    for(int i = 0; i < (1<<(n+1)); i++){
        dp[i] = -1;
    }

    ll ans = no_of_ways(n, dp,0);
    cout << ans << endl;
}
