#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int min_time(int N, int D, int P, int K, vector<int> dist, vector<int> petrol){
    
    int curr = P;
    int ans = P;
    unordered_map<int,int> m;
    
    for(int i = 0; i < N; i++){
        m[dist[i]] = petrol[i];
    }
    sort(dist.begin(), dist.end());
    
    while(curr < D){
        int i = lower_bound(dist.begin(), dist.end(), curr) - dist.begin();
        cout << i << endl;
        if(i == 0){
            ans += (dist[0] - curr)*5;
            curr = dist[0];
        }else {
            curr += m[dist[i]];
            if(curr > D){
                curr -= m[dist[i]];
                int ans1 = 5 * (D -curr);
                int ans2 = K + (D- curr);
                ans += min(ans1, ans2);
                curr = D;
            }else{
                int ans1 = K + (m[dist[i]]);
                int ans2 = 5 * (m[dist[i]]);
                ans += min(ans1, ans2);
                
            }
        }
    }
    return ans;
}

int main() {
	// your code goes here
	
	int N, D, P, K;
	cin >> N >> D >> P >> K;
	
	vector<int > dist;
	int dis;
	for(int i = 0; i < N; i++){
	    cin >> dis;
	    dist.push_back(dis);
	}
	int pet;
	vector<int> petrol;
	for(int i = 0; i < N; i++){
        cin >> pet;
	    petrol.push_back(pet);
	}
	
	int ans = min_time(N, D, P, K, dist, petrol);
    cout << ans << endl;
	return 0;
}
