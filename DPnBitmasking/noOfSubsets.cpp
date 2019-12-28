#include<bits/stdc++.h>
using namespace std;

int noOfSubsets(int* arr, int n, int k){

	int count = 0;

	for(int i = 0; i < (1 << n); i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << (n-j-1))){
				sum += arr[j];
			}
		}

		if(sum == k){
			count++;
		}
	}

	return count;
}

int main(){

	int n, k;
	cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cin >> k;

	int count;
	count = noOfSubsets(arr, n, k);
	cout << count << endl;
}