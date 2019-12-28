#include<bits/stdc++.h>
using namespace std;

int main(){


	// freopen("encyin.txt","r",stdin);
	// freopen("encyout.txt","w",stdout);

	int n , q;
	cin >> n >> q;
	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int page;
	while(q > 0){
		cin >> page;
		cout << arr[page- 1]<<endl;
		q--;
	}

	return 0;
}