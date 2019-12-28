#include<bits/stdc++.h>
using namespace std;



// long long merge(long long arr[], long n, long mid){

// 	long long count = 0;
// 	long n1 = mid;
// 	long n2 = mid +(n-mid)/2;

// 	long long L[n1], R[n2];
// 	for(int i = 0; i < n1; i++){
// 		L[i] = arr[i];
// 	} 
// 	for(int j = 0; j < n2; j++){
// 		R[j] = arr[mid + j];
// 	}
// 	int i = 0;
// 	int j = 0; 
// 	int k = 0;
// 	while(i < n1 && j < n2){
// 		if(L[i] <= R[j]){
// 			arr[k++] = L[i++];
// 		}
// 		else{
// 			int m = n1-i;
// 			count += m;
// 			arr[k++] = R[j++];
// 		}
// 	}
// 	if(i < n1){
// 		arr[k++] = L[i++];
// 	}
// 	if(j < n2){
// 		arr[k++] = R[j++];
// 	}
// 	for(int i = 0; i < n; i++){
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// 	return count;
// }
// long long solve(long long arr[] ,long n){

// 	if(n == 1){
// 		return 0;
// 	}
// 	long mid = n/2;
// 	long long left_count = solve(arr, n/2);
// 	long long right_count = solve(arr + mid, n/2);
// 	cout << left_count <<" " << right_count << endl;
	
// 	long long merge_count = merge(arr, n, mid);
// 	cout << merge_count << endl << endl;
	
// 	return 4+ merge_count;
//  }

long long merge(long long arr[], long left, long mid, long right){

	long long count = 0;

	int k = 0;
	int i = left;
	int j = mid;
	
	long long temp[right - left + 1];

	while(i < mid && j <= right){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			count += (mid-i);
		}
	}

	while(i < mid){
		temp[k++] = arr[i++];
	}

	while(j <= right){
		temp[k++] = arr[j++];
	}

	for(i = left, k= 0; i <= right; i++, k++){
		arr[i] = temp[k];
	}

	return count;
}

long long merge_sort(long long arr[] , long left, long right){

	long long count = 0;
	if(right > left){
		long mid = (left + right)/2;
		long long left_count = merge_sort(arr, left, mid);
		long long right_count = merge_sort(arr, mid + 1, right);
		long long mycount = merge(arr, left, mid + 1, right);
		return (left_count + right_count + mycount);
	}
	return count;
}

long long solve(long long arr[], long n){
	long long ans = merge_sort(arr,0,n-1);
	return ans;
}

int main(){
	long n;
	cin >> n;
	long long arr[n];

	for(long i = 0; i < n; i++){
		cin >> arr[i];
	}
	long long count;
	count = solve(arr,n);
	cout << count << endl;

}