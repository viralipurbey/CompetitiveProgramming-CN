#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n){
	int curr_sum = 0;
	int best_sum = 0;
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
int main(){

	int arr[] = {3,4,-1,4,6,8, -10, 7, 9, 5};
	cout << kadane(arr, 10) << endl;
	return 0;

}