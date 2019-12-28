#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool comp(long long a,long long b){
	return a > b;
}
long long check(long long arr[], int n, long long k, long long left, long long right){

	long long ans = 0;
	while(left <= right){
		long long mid = left +(right - left)/2;
		long long no_of_students = 0;
		for(int i = 0; i < n; i++){
			long long no = (arr[i] / mid);

			no_of_students += no;

			if(no_of_students >= k){
				ans = mid;
				break;
			}	
		}
		cout << no_of_students << ans << mid << endl;
		if(ans == mid){
			left = mid + 1;
		}
		else{
			right = mid -1;
		}
	}
	return ans;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		long long k;
		cin >> N >> k;
		long long arr[N];
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}

		sort(arr,arr + N,comp);

		long long max = arr[0];
		long long min = 1;

		long long ans = check(arr, N,k, min, max);
		cout << ans << endl;
	}
}