#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
	int N, k;
	cin >> N >> k;
	int arr[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
 	long count = 0;
	sort(arr, arr + N);

	// by two pointers approach
	// for(int i = 0; i < N; i++){
	// 	for(int j = i+ 1; j < N; j++){
	// 		if((arr[j] - arr[i]) >= k){
	// 			count +=(N-j);
	// 			break;
	// 		}
	// 	}
	// }

	//by binary search approach
	int low = -1;
	for(int i = 0; i < N; i++){
		int l = i + 1; 
		int r = N-1;
		while(l < r){
			int mid = (l + r)/2;
			if((arr[mid] - arr[i]) >= k){
				low = mid;
				cout << low << endl;
				r = mid;
			}
			else{
				l = mid;
			}
		}
		if(low != -1){
			count += (N-low);
		}
	}

	cout << count << endl;
}