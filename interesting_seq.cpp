#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    int k , l;
    cin >> k >> l;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for(int i = 1; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
        
        if(min > arr[i]){
            min = arr[i];
        }
    }
    long min_cost = INT_MAX;
    
    for(int i = min; i <= max; i++){
        
        int ele = i;
        long cost ;
        int inc = 0;
        int dec = 0;
        
        for(int j = 0; j < n; j++){
            if(arr[i] > ele){
                dec += (arr[j] - ele);
            }
            if(arr[i] < ele){
                inc += (ele - arr[j]);
            }
        }
        
        if(inc >= dec){
            cost = (dec * k) + ((inc - dec) * l);
            if(min_cost > cost){
                min_cost = cost;
             }
        }
        
    }
    cout << min_cost << endl;
    return 0;
}