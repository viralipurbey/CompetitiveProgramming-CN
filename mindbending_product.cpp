#include <bits/stdc++.h>
using namespace std;
long* mindbending_product(int arr[] , int n, long P[]){
	long lPE = 1;
	long rPE = 1;
	for(int i = 0; i < n; i++){
		P[i] = lPE;
		lPE = lPE * arr[i];
	}
	for(int i = n-1; i >= 0; i--){
		P[i] = P[i] * rPE;
		rPE = rPE * arr[i];
	}
	return P;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	long* P = new long[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	P = mindbending_product(arr, n, P);
	for(int i = 0; i < n; i++){
		cout << P[i] <<" ";
	}
	cout << endl;
	delete[] arr;
	delete[] P;
	return 0;
}