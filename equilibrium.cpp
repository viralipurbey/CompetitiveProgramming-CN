#include<bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n){

	if(n==1)
		return 1;

	int *leftsum = new int[n];
	int *rightsum = new int[n];

	for(int i = 1; i < n; i++){
		leftsum[i] = leftsum[i-1] + arr[i-1];
	} 

	for(int i = n-2; i >= 0; i--){
		rightsum[i] = rightsum[i+1] + arr[i+1];
	} 

	for(int i = 0; i < n; i++){
		if(leftsum[i] == rightsum[i]){
			return i+1;
		}
	}
	return -1;
}

int main(){

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n; 
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		int index = equilibrium(arr,n);
		cout << index << endl;
	}
	return 0;

}