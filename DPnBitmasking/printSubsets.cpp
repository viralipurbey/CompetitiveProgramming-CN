#include<bits/stdc++.h>
using namespace std;

void printSubsets(int *arr, int n){

	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 <<(n- j -1))){
				cout << arr[j] <<" ";
			}
		}

		cout << endl;
	}
}
int main(){

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	printSubsets(arr, n);
}