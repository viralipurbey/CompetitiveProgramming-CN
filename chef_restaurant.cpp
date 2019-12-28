#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int N, M;
		cin >> N >> M;
		vector<pair<int,int> > intervals;
		for(int i = 0; i < N; i++){
			int left, right;
			cin >> left >> right;
			intervals.push_back(make_pair(left, right));

		}

		sort(intervals.begin(), intervals.end());


		int time;
		int index;
		int wait;

		while(M--){
			cin >> time;
			index = (lower_bound(intervals.begin(),intervals.end(),make_pair(time,0)) - intervals.begin());

			if(index == 0){
				if(time >= intervals[index].first){
					wait = 0;
				}
				else{
					wait = intervals[index].first - time;
				}
			}
			else {
					
				if(time < (intervals[index - 1].second)){
					wait = 0;
				}
				else if(index < intervals.size()){
					wait = intervals[index].first - time;
				}
				else{
					wait = -1;
				}
		
			}
			
			cout << wait << endl;

		}
	}
	return 0;
	
}

