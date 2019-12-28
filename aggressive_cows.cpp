#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		long N , C;
		cin >> N >> C;
		long long *arr = new long long[N];
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		sort(arr, arr+N);

		long long start = 0;
		long long end = arr[N-1] - arr[0];
		long long ans = -1;
		while(start <= end){
			long long mid = start + (end - start)/2;
			bool flag = false;
			int count = 1;
			int j = 0;
			for(int i = 1; i < N;i++ ){
				if((arr[i] - arr[j]) >= mid){
					j = i;
					count++;
				}
				if(count == C){
					flag = true;
					break;
				}
			}
			
			
			if(flag == true){
				start = mid + 1;
				ans = mid;
			}
			else{
				end = mid -1;
			}
			

		}

		cout << best_ans << endl;

	}
}