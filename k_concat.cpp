#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll kadane(int *arr, int n){
	ll curr_sum = 0;
	ll best_sum = 0;
	for(int i = 0; i < n; i++){
		curr_sum += arr[i];
		if(best_sum < curr_sum)
			best_sum = curr_sum;
		if(curr_sum < 0){
			curr_sum = 0;
		}
	}
	return best_sum;
}
ll k_concat(int *arr, int n, int k){

	ll kadane_sum = kadane(arr, n);
	ll total_sum = 0;
	ll best_prefix_sum = 0;
	ll best_suffix_sum = 0;
	ll curr_sum = 0;
	ll best_sum = 0;
	for(int i = 0; i < n; i++){
		curr_sum += arr[i];
		if(best_sum < curr_sum)
			best_sum = curr_sum;
		best_prefix_sum = best_sum;
	}
	curr_sum = 0;
	best_sum = 0;
	for(int i = n-1; i >=0; i--){
		curr_sum += arr[i];
		if(best_sum < curr_sum)
			best_sum = curr_sum;
		best_suffix_sum = best_sum;
	}
	for(int i = 0; i < n; i++){
		total_sum += arr[i];
	}
	if(k==1){
		return kadane_sum;
	}
	else{
		if(total_sum >= 0){
			ll maximum = (best_prefix_sum + total_sum *(k-2) + best_suffix_sum);
			if(kadane_sum > maximum)
				maximum = kadane_sum;
			return maximum;
		}
		else{
			ll maximum = best_prefix_sum + best_suffix_sum;
			if(kadane_sum > maximum)
				maximum = kadane_sum;
			return maximum;
		}

	}
}
int main(){
	int T;
	cin >> T;
	while(T > 0){
		int n;
		cin >> n;
		int k;
		cin >> k;
		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int max = k_concat(arr, n , k);
		cout << max << endl;
		delete[] arr;
		T--;

	}

}