#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int prefix[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
		prefix[i] = sum;
	}

	int q;
	cin >> q;
	int x;
	int ans = 0;
	while(q--){
		cin >> x;
        
        ans = upper_bound(prefix,prefix+n,x)-prefix-1;
        int rem = x-prefix[ans];

		cout << ans + 1<<" " << rem << endl;
	}
}