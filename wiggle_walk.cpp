#include<bits/stdc++.h>
using namespace std;

void solve(int n, int r,int c, int sr, int sc, string ins, int test){
    
    int **dp = new int*[r+1];
    for(int i = 0; i <= r; i++){
        dp[i] = new int[c+1]();
    }
    
    dp[sr][sc] = 1;
    int curr_r = sr;
    int curr_c = sc;
     
    for(int i = 0; i < n; i++){
        if(ins[i] == 'N'){
            curr_r--;
            while(dp[curr_r][curr_c] == 1){
                curr_r--;
            }
        }
        else if(ins[i] == 'S'){
            curr_r++;
            while(dp[curr_r][curr_c] == 1){
                curr_r++;
            }
        }
        else if(ins[i] == 'W'){
            curr_c--;
            while(dp[curr_r][curr_c] == 1){
                curr_c--;
            }
        }
        else if(ins[i] == 'E'){
            curr_c++;
            while(dp[curr_r][curr_c] == 1){
                curr_c++;
            }
        }
        
        dp[curr_r][curr_c] = 1;
        
    }
    
    cout << "Case #" << test <<": "<<curr_r <<" "<< curr_c << endl;
    
    for(int i = 0; i <= r; i++){
        delete[] dp[i];
    }
    
    delete[] dp;
    return;
}

int main(){
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        int n, r, c, sr, sc;
        
        cin >> n >> r >> c >> sr >> sc;
        string ins;
        
        cin >> ins;
        
        solve(n,r,c,sr,sc, ins, i+1);
    }
    return 0;
}