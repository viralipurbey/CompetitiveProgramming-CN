#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main(){
	vector<ll> v;
	//cout << v.size();
	int m , n;
	cin >> n >> m;
	for(int i =0; i < n; i++){
		ll val;
		cin >> val;
		v.push_back(val );
	}
	//cout <<"**********";
	sort(v.begin(), v.end());
	vector<ll>::iterator it;
	for(it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl; 
	ll* endP = &v[n-1];
	queue<ll> q;
	int count_m = 0;
	// for(int i =0; i < m; i++ ){
	// 	int curr_m;
	// 	cin >> curr_m;
	// 	ll large;
	// 	for(; count_m < curr_m; count_m++){
	// 		if(q.empty()){
	// 			large = *endP;
	// 			cout << large << endl;
	// 			endP--;
	// 			q.push(large/2);
	// 			cout << q.front() << endl;
	// 		}
	// 		else if(v.size() == 0){
	// 			large = q.front();
	// 			cout << large << endl;
	// 			q.pop();
	// 			q.push(large/2);
	// 		}
	// 		else{
	// 			if(q.front() > *endP){
	// 				large = q.front();
	// 				cout << large << endl;
	// 				q.pop();
	// 				q.push(large/2);
	// 			}
	// 			else{
	// 				large = *endP;
	// 				cout << large << endl;
	// 				endP--;
	// 				q.push(large/2);
	// 			}
	// 		}
	// 	}
		
	// }	
	while(m--){
		int curr_m;
		cin >> curr_m;
		ll ans;
		for(; count_m < curr_m; count_m++){
			if((v.size() != 0) && ((q.empty()) || (*endP >= q.front()))){
				ans = *endP;
				endP--;
			}
			else{
				ans = q.front();
				q.pop();
			}
			q.push(ans/2);

		}
		cout << ans << endl;
	}
}