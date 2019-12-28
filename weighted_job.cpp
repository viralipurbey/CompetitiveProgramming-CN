#include<bits/stdc++.h>
using namespace std;

struct job{
	int start;
	int finish;
	int profit;
};

bool comp(job j1, job j2){
	return j1.finish < j2.finish;
}

int job_sched(job jobs[], int n){

	sort(jobs,jobs + n,comp);
	int dp[n];
	dp[0] = jobs[0].profit;
	for(int i = 1; i < n; i++ ){
		// for(int j = i-1; j >= 0; j--){
		// 	if(jobs[j].finish <= jobs[i].start){
		// 		dp[i] = jobs[i].profit + dp[j];
		// 		break;
		// 	}
		// }

		int l = 0;
		int r = i-1;
		int index = -1;

		dp[i] = jobs[i].profit;
		while(l <= r){

			int mid = (l+r)/2;

			if(jobs[mid].finish <= jobs[i].start){
				l = mid + 1;
				index = mid;
			}
			else{
				r = mid -1;
			}
		}

		if(index != -1){
			dp[i] += dp[index];
		}

		dp[i] = max(dp[i] , dp[i-1]);
	}

	int ans = dp[n-1];
	return ans;

}

int main(){

	int n;
	cin >> n;

	job jobs[n];
	for(int i = 0; i < n; i++){
		cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
	}

	int profit = job_sched(jobs,n);
	cout << profit << endl;
	return 0;

}