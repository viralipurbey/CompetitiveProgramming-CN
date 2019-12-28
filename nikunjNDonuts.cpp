#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
	return a > b;
}

int calc_cal_value(int arr[], int n){

	int value = 0;
	sort(arr,arr+n,comp);

	for(int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
	for(int i = 0; i < n; i++){
		value += (arr[i] * pow(2,i));
	}

	return value;

}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int value = calc_cal_value(arr,n);
	cout << value << endl;
	return 0;
}