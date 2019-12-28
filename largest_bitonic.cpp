#include<bits/stdc++.h>
using namespace std;

int bitonic(int arr[], int n){
	int *inc = new int[n];
	inc[0] = 1;
	for(int i = 1; i < n; i++){
		inc[i] = 1;
		for(int j = i-1; j >= 0; j--){
			if(arr[j] < arr[i]){
				int curr = inc[j] + 1;
				if(curr > inc[i]){
					inc[i] = curr;
				}
			}
		}
	}

	int *dec = new int[n];
	dec[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		dec[i] = 1;
		for(int j = i + 1; j <n; j++){
			if(arr[j] < arr[i]){
				int curr = dec[j] + 1;
				if(curr > dec[i]){
					dec[i] = curr;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		inc[i] = inc[i] + dec[i] - 1;
	}//

	int best = 0;

	for(int i = 0; i < n; i++){
		if(best < inc[i]){
			best = inc[i];
		}
	}

	delete[] inc;
	delete[] dec;
	return best;

}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << bitonic(arr,n) << endl;
	return 0;
}