#include <bits/stdc++.h>
using namespace std;

void sorting(int arr[], int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count0++;
        }
        if(arr[i] == 1){
            count1++;
        }
        if(arr[i] == 2){
            count2++;
        }
    }
    int j = 0;
    
    for(int i = 0; i < count0; i++){
        arr[j++] = 0;
    }
     for(int i = 0; i < count1; i++){
        arr[j++] = 1;
    }
     for(int i = 0; i < count2; i++){
        arr[j++] = 2;
    }
}

int main() {
	//code
	
	int T;
	cin >> T;
	while(T--){
	    int n;
	    cin >> n; 
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    sorting(arr,n);
	    for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
	    cout << endl;
	}
	return 0;
}