#include<bits/stdc++.h>
using namespace std;
/*int maxSubarrayPossible(int arr[] , int n){
	int curr_prod = 1;
	int best_so_far = 0;
	for(int i = 0; i < n; i++){
		curr_prod *= arr[i];
		//cout << curr_prod << endl;
		if(best_so_far < curr_prod){
			best_so_far = curr_prod;
		}
		if(curr_prod == 0){
			curr_prod = 1;
		}
	}
	return best_so_far;
}
*/
int maxSubarrayPossible(int arr[], int n){
	int maximum = 0;
	int max_ending_here = 1;
	int min_ending_here = 1;
	for(int i = 0; i < n; i++){
		if(arr[i] > 0){
			max_ending_here = max_ending_here * arr[i];
			min_ending_here = min(1, min_ending_here * arr[i]);
		}
		else if( arr[i] < 0){
			int temp = min_ending_here;
			min_ending_here = max_ending_here * arr[i];
			max_ending_here = max(1, temp * arr[i]);
		}
		else{
			min_ending_here = 1;
			max_ending_here = 1;
		}
		if(maximum < max_ending_here){
			maximum = max_ending_here;
		}
	}
	return maximum;

}
int main(){
	int n;
	cin >> n;
	int *arr= new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = maxSubarrayPossible(arr, n);
	cout << ans << endl;
	delete[] arr;
	return 0;
}