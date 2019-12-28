#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int activity_sel(pair<int,int> time[], int n){

	sort(time,time + n,comp);

	int curr_fin = time[0].second;
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(time[i].first >= curr_fin){
			ans++;
			curr_fin = time[i].second;
		}
	}

	return ans;

}

int main(){

	int n;
	cin >> n;
	pair<int,int> time[n];
	for(int i = 0; i < n; i++){
		cin >> time[i].first >> time[i].second;
	}

	int ans = activity_sel(time ,n);
	cout << ans << endl;

	return 0;
}