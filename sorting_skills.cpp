#include<bits/stdc++.h>
using namespace std;

void swap(int & x, int & y){
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        int num[n];
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }
        
        for(int i = 0; i < n; i++){
            if(num[i+1] == (num[i] - 1)){
                swap(num[i+1],num[i]);
            }
        }
        bool flag = true;
        for(int i = 0; i < n -1; i++){
            if((num[i] + 1) != num[i+1]){
                flag = false;
            }
        }
        if(flag){
            cout <<"Yes" << endl;
        }
        else{
            cout <<"No" << endl;
        }
    }
	return 0;
}
