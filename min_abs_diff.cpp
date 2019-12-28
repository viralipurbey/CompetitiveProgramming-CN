#include<bits/stdc++.h>
using namespace std;

int cal_diff(int arr[], int n){
	sort(arr,arr+n);
	int prev = arr[0];
	int min = INT_MAX;
	for(int i = 1; i < n; i++){
		int curr_diff = arr[i] - prev;
		prev = arr[i];
		if(min > curr_diff){
			min = curr_diff;
		}
	}

	return min;

}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int min = cal_diff(arr,n);
	cout << min << endl;
	return 0;
}