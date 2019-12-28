#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ans = -1;
    int values[n];
    for(int i = 0; i < n; i++){
        int val = (arr[i] - i)/n;
        if(((arr[i] - i) % n)!= 0){
            val = val + 1;
        }
        
        values[i] = val;
    }

    // for(int i = 0; i < n; i++){
    //     cout << values[i] << endl;
    // }
    
    int min = values[0];
    for(int i = 1; i < n; i++){
        if(values[i] < min){
            min = values[i];
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
