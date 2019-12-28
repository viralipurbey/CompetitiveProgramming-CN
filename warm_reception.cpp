#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int* arrival = new int[n];
	for(int i =0; i < n; i++){
		cin >> arrival[i];
	}
	int* departure = new int[n];
	for(int i = 0; i < n; i++){
		cin >> departure[i];
	}
	int no_of_chairs = 0;
	
	sort(arrival, arrival+n);
	sort(departure, departure + n);

	int j = 0;
	for(int i =0; i < n; i++){
		if(arrival[i] >= departure[j]){
			j++;
		}
		else{
			no_of_chairs++;
		}
	}

	cout << no_of_chairs << endl;
	return 0;

}