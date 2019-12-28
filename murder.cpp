#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long merge(int arr[], int l,int mid ,int r){
	int i = l;
	int j = mid;
	int k = 0;
	long count = 0;
	int temp[r - l + 1];

	while(i < mid && j <= r){
		if(arr[i] < arr[j]){
			count += (r-j + 1)* arr[i];
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}

	while(i < mid){
		temp[k++] = arr[i++];
	}

	while(j <= r){
		temp[k++] = arr[j++];
	}

	for(i = l,k = 0; i <= r; i++, k++){
		arr[i] = temp[k];
	}

	return count;
}


long solve(int arr[],int l, int h){

	while(l < h){
		int mid = (l+h)/2;
		long leftans = solve(arr, l ,mid);
		long rightans = solve(arr, mid + 1, h);
		long mergeans = merge(arr, l, mid + 1, h);
		long ans = leftans + rightans + mergeans;
		return ans;
	}
	return 0;

}
int main(){
	int T;
	cin >> T;
	long total = 0;
	while(T--){
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		
		total = solve(arr,0, N-1);
		cout << total << endl;
	}
}