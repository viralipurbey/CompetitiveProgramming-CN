#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
	cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int sum = 0;
	int nog;
	int nol;
	for(int i = 0; i < (n/2); i++){
		sum = arr[i] + arr[n-i-1];
		nog = sum / 10;
		nol = sum % 10;
		cout << nog <<" "<<nol << endl;

	}
	return 0;
}
